#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("") {}

ScalarConverter::ScalarConverter(std::string input) : _input(input) {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) : _input(obj._input) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this == &obj)
		return *this;
	_input = obj._input;
	return *this;
}

void ScalarConverter::convert()
{
	try
	{
		if (_input.length() == 1 && !isdigit(_input[0]))
			convertChar();
		else if (_input.length() == 3 && _input[0] == '\'' && _input[2] == '\'')
			convertChar();
		else if (_input == "nan" || _input == "-inff" || _input == "+inff" || _input == "inf")
			convertSpecial();
		else
			convertNumber();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convertChar()
{
	char c = _input[0];
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertSpecial()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << _input << "f" << std::endl;
	std::cout << "double: " << _input << std::endl;
}

void ScalarConverter::convertNumber()
{
	char *end;
	double d = std::strtod(_input.c_str(), &end);
	if (*end)
		throw ScalarConverter::ImpossibleException();
	std::cout << "char: ";
	if (isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}

