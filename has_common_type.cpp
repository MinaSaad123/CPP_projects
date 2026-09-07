#include <iostream>
#include <vector>
#include <type_traits>

template <typename, typename...Args>
struct has_common_type : std::false_type {

};

template <typename...Args>
struct has_common_type<
	std::void_t<std::common_type_t<Args...>>, 
	Args...> 
	: std::true_type {

};

template <typename... Ts>
constexpr bool has_common_type_v = sizeof...(Ts) < 2 ||
								   has_common_type<void, Ts...>::value;

int main() {
	
}