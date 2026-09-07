#include <iostream>
#include <vector>

template <typename T, typename...Ts,
		 typename Allocator = std::allocator<T>>
auto make_vector(T&& first, Ts&&...args ) {
	return std::vector<std::decay_t<T>, Allocator> {
		std::forward<T>(first),
		std::forward<T>(args)...
	};
}

int main() {
	auto v = make_vector( 1,2,3,4,5 );

}