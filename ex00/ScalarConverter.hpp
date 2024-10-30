#ifndef SCLARCONVERTER_HPP
#define SCLARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
	std::string _input;
public:
	ScalarConverter();
	ScalarConverter(std::string input);
	ScalarConverter(const ScalarConverter &obj);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &obj);

	void convert();
	void convertChar();
	void convertSpecial();
	void convertNumber();

	class ImpossibleException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		virtual const char *what() const throw();
	};

};


#endif