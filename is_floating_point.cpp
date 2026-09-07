#include <iostream>
#include <vector>
#include <memory>

template <typename T>
struct remove_reference
{
	using value_type = T;
};

template <typename T>
struct remove_reference<T&> {
	using value_type = T;
};

template <typename T>
struct remove_reference<T&&> {
	using value_type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::value_type;

template <typename T>
remove_reference_t<T>&& move(T&& arg) {
	return  static_cast<remove_reference_t<T> &&>(arg);
}

int main() {
	

}