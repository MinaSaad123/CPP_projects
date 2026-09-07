#include <iostream>
#include <vector>
#include <memory>

template <bool, typename T = void>
struct enable_if {

};

template <typename T>
struct enable_if<true, T> {
	using value_type = T;
};

int main() {
	
}