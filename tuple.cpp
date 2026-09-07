#include <iostream>
#include <array>

template<size_t N, typename T, typename...Ts>
struct nth_type : nth_type<N - 1, T, Ts...> {
	static_assert(N < sizeof...(Ts) + 1, "outside the bound");
};

template <typename T, typename...Ts >
struct nth_type<0, T, Ts...> {
	using value_type = T;
};

template<typename T, typename...Ts>
struct tuple {
	
	tuple(T const& t, Ts const &... ts)
		: value(t), rest(ts...)
	{
	}

	constexpr auto size() {
		return 1 + rest.size();
	}

	T value;
	tuple<Ts...> rest;
};

template<typename T>
struct tuple<T> {

	tuple(const T& t)
		: value(t)
	{
	}
	constexpr auto size() {
		return 1;
	}
	T value;

};

template <size_t N, typename...Ts>
typename nth_type<N, Ts...>::value_type& get(tuple<Ts...>& t) {
	return get<N - 1>(t.rest);
}

template <>
typename nth_type<0, Ts...>::value_type& get(tuple<Ts...>& t) {
	return get<N - 1>(t.reset);
}

int main()
{
}