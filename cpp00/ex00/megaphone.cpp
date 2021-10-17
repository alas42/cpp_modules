#include <iostream>
#include <string>
#include <locale>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	std::locale loc;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << std::toupper(argv[i][j], loc);
			j++;
		}
		i++;
	}
	std::cout << "\n";
	return (0);
}