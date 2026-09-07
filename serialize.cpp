#include <iostream>
#include <vector>
#include <memory>

struct widget {
	int id;
	std::string name;

	std::ostream& write(std::ostream& os) const {
		os << name << id;
		return os;
	}
};

struct gadget {
	int id;
	std::string name;

	friend std::ostream& operator <<(std::ostream& os, gadget const& O);
};

std::ostream& operator <<(std::ostream& os, gadget const& O) {
	os << O.name << " " << O.id;
	return os;
}

template <typename T>
struct use_write {
	static constexpr bool value = false;
};

template <>
struct use_write<widget> {
	static constexpr bool value = true;
};
 
//template variable
template <typename T>
inline constexpr bool uses_write_v = use_write<T>::value;

template <bool>
struct serializer {
	template <typename T>
	static void serialize(std::ostream& os, T const& value) {
		os << value;
	}
};

template <>
struct serializer<true> {
	template <typename T>
	static void serialize(std::ostream& os, T const& value) {
		write(os);
	}
};

template <typename T>
void serialize(std::ostream& os, T const& value)
{
	serializer<uses_write_v<T>>::serialize(os, value);
}

int main() {
	

}