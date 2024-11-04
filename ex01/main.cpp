#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.n = 42;
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	std::cout << ptr->n << std::endl;
	return 0;
}