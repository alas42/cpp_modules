#include <string>
#include <iostream>
#include <climits>
#include <cmath>

/*
** DISPLAY RESULT
*/
void	displayLimit(std::string const & s1, std::string const & s2, std::string const & s3, std::string const & s4)
{
	std::cout << "char: " << s1 << "\n"
		<< "int: " << s2 << "\n"
		<< "float: " << s3 << "\n"
		<< "double: " << s4 << std::endl;
}

void	display(char s1, int s2, float s3, double s4)
{
	if (isprint(s1))
	{
		std::cout << "char: '" << s1 << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << s2 << std::endl;
	if (s3 - s2 == 0)
	{
		std::cout << "float: " << s3 << ".0f\n"
			<< "double: " << s4 << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << s3 << "f\n"
			<< "double: " << s4 << std::endl;
	}
}

bool	isValidNumber(std::string const & arg)
{
	bool point = 0;
	bool f = 0;
	size_t i = 0;

	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (i < arg.length())
	{
		if (f == 1)
			return (0);
		if (arg[i] < '0' || arg[i] > '9')
		{
			if (arg[i] == '.' && point == 0)
			{
				point = 1;
				i++;
				continue;
			}
			if (arg[i] == 'f' && f == 0 && point == 1)
			{
				f = 1;
				i++;
				continue;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

/*
** CHECKING THE TYPE OF THE INPUT
*/
bool	isLimitFloat(std::string const & arg)
{
	if (!arg.compare("nanf") || !arg.compare("+inff") || !arg.compare("-inff"))
		return (1);
	return (0);
}

bool	isLimitDouble(std::string const & arg)
{
	if (!arg.compare("nan") || !arg.compare("+inf") || !arg.compare("-inf"))
		return (1);
	return (0);
}

bool	isValidChar(std::string const & arg)
{
	if (arg.length() == 1 && isprint(arg[0]) && (!(arg[0] >= '0' && arg[0] <= '9')))
		return (1);
	return (0);
}

bool	isInt(std::string const & arg)
{
	if (arg.find('.') != std::string::npos || arg.find('f') != std::string::npos)
		return (0);
	return (1);
}

bool	isDouble(std::string const & arg)
{
	if (isLimitDouble(arg))
		return (1);
	if (arg.find('.') == std::string::npos || arg.find('f') != std::string::npos)
		return (0);
	return (1);
}

bool	isFloat(std::string const & arg)
{
	if (isLimitFloat(arg))
		return (1);
	if (arg.find('.') == std::string::npos || arg.find('f') == std::string::npos)
		return (0);
	return (1);
}

/*
** CONVERSIONS
*/
int convert_from_char(std::string const & arg)
{
	char	input = arg[0];
	float	float_num = static_cast<float>(input);
	int		integer = static_cast<int>(input);
	double double_num = static_cast<double>(input);
	display(input, integer, float_num, double_num);
	return (0);
}

int convert_from_int(std::string const & arg)
{
	int		input = atoi(arg.c_str());
	char	character = static_cast<char>(input);
	float	float_num = static_cast<int>(input);
	double	double_num = static_cast<double>(input);
	display(character, input, float_num, double_num);
	return (0);
}

int convert_from_float(std::string const & arg)
{
	if (isLimitFloat(arg))
	{
		displayLimit("impossible", "impossible", arg, arg.substr(0, arg.length() - 1));
		return (0);
	}
	float input = atof(arg.c_str());
	int integer = static_cast<int>(input);
	double double_num = static_cast<double>(input);
	char character = static_cast<char>(input);
	display(character, integer, input, double_num);
	return (0);
}

int convert_from_double(std::string const & arg)
{
	if (isLimitDouble(arg))
	{
		std::string new_str = arg;
		new_str.append("f");
		displayLimit("impossible", "impossible", arg, new_str);
		return (0);
	}
	double	input = strtod(arg.c_str(), NULL);
	int		integer = static_cast<int>(input);
	char	character = static_cast<char>(input);
	float	float_num = static_cast<float>(input);
	display(character, integer, float_num, input);
	return (0);
}

/*
** MAIN FUNCTION
*/
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./scalar_conversion <string_representation>" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	bool (* isType [])(std::string const &) = {&isValidChar, &isInt, &isDouble, &isFloat};
	int (* convert [])(std::string const &) = {&convert_from_char, &convert_from_int, &convert_from_double, &convert_from_float};

	if (!isValidNumber(input) && !isValidChar(input) && !isLimitDouble(input) && !(isLimitFloat(input)))
	{
		std::cerr << "Not a Valid input" << std::endl;
		return 1;
	}
	for (int i = 0; i < 4; i++)
	{
		if (isType[i](input))
			return convert[i](input);
	}
	std::cerr << "Not a Valid input" << std::endl;
	return 0;
}
