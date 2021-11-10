#include "Karen.hpp"

int	main(void)
{
	{
		Karen karen;
		karen.complain("nothing");
	}
	{
		std::cout << std::endl;
		Karen karen;
		karen.complain("INFO");
	}
	{
		std::cout << std::endl;
		Karen karen;
		karen.complain("WARNING");
	}
	{
		std::cout << std::endl;
		Karen karen;
		karen.complain("ERROR");
		karen.complain("DEBUG");
	}
	{
		std::cout << std::endl;
		Karen karen;
		karen.complain("ERROR");
		karen.complain("WARNING");
		karen.complain("INFO");
		karen.complain("DEBUG");
	}
	return 0;
}
