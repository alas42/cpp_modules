#include "Karen.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Karen karen;
		karen.complain(argv[1]);
	}
	else
	{
		std::cout << "Usage: ./karenFilter [level]" << std::endl;
		return 1;
	}
	return 0;
}
