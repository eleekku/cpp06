#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &source) {
	*this = source;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void ScalarConverter::convert(const std::string &input)
{
    try
    {
        if (input.length() == 1 && !isdigit(input[0]))
            convertChar(input);
        else if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
            convertChar(input.substr(1, 1));
        else if (input == "nan" || input == "-inff" || input == "+inff" || input == "inf")
            convertSpecial(input);
        else if (input.length() > 1 && input[input.length() - 1] == 'f')
            convertFloat(input);
        else
            convertNumber(input);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "impossible" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "impossible" << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void convertChar(const std::string &input)
{
    char c = input[0];
    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertSpecial(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << input << "f" << std::endl;
    std::cout << "double: " << input << std::endl;
}

void convertFloat(const std::string &input)
{
    char *end;
    float f = std::strtof(input.c_str(), &end);
    if (*end != 'f' || *(end + 1) != '\0')
        throw std::invalid_argument("impossible");
    std::cout << "char: ";
    if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max() && isprint(static_cast<int>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertNumber(const std::string &input)
{
    char *end;
    double d = std::strtod(input.c_str(), &end);
    if (*end)
        throw std::invalid_argument("impossible");
    std::cout << "char: ";
    if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max() && isprint(static_cast<int>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}