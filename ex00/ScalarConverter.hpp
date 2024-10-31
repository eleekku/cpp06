#ifndef SCLARCONVERTER_HPP
#define SCLARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &obj);
	public:
		static void convert(const std::string &input);
};

	void convertChar(const std::string &input);
	void convertSpecial(const std::string &input);
	void convertNumber(const std::string &input);
	void convertFloat(const std::string &input);



#endif