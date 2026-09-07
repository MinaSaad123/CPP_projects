#include <iostream>

//any variable in unnamed namespaces is static life time

//An unnamed namespace may be discontiguous within a given file but does not span files

namespace local {
	namespace {
		int i;
	}
}

int main() {
	// ok: i defined in a nested unnamed namespace is distinct from global i
	local::i = 42;

	return 0;
}