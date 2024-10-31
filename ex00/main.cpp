#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	try {
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}