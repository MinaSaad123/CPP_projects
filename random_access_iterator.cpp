#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <iterator>
#include <concepts>

template <typename I>
concept random_access_iterator = std::bidirectional_iterator<I> &&
std::derived_from<typename std::iterator_traits<I>::iterator_category,
	std::random_access_iterator_tag>&&
std::totally_ordered<I>&&
std::sized_sentinel_for<I, I>&&
	requires(I i, const I j, const std::iter_difference_t<I> n) {
		{ i += n } -> std::same_as<I&>;
		{ j + n } -> std::same_as<I>;
		{ n + j } -> std::same_as<I>;
		{ i -= n } -> std::same_as<I&>;
		{ j - n } -> std::same_as<I>;
		{ j[n] } -> std::same_as<std::iter_reference_t<I>>;
};
								 
int main() {
	
	static_assert(random_access_iterator<std::vector<int>::iterator>, "Not equal");
	static_assert(random_access_iterator<std::list<int>::iterator>, "Not equal");
}