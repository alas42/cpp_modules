#include <iostream>
#include <string>
#include <locale>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	std::locale loc;
	std::string	print_string;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			print_string.push_back(std::toupper(argv[i][j]));
			j++;
		}
	}
	std::cout << print_string << std::endl;
	return (0);
}
