#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
# include <cstdlib>
# include <ctime>

Base * generate(void)
{
	std::srand(std::time(0));
	int result = (std::rand()%3) + 1;
	switch (result)
	{
		case 3:
			return new A;
		case 2:
			return new B;
		default:
			return new C;
	}
	return NULL;
}
/*
void	identify(Base * p)
{
	//using dynamic cast (the one hat throw errors on run-time, so that we can catch the errors)
}

void	identify(Base & p)
{
	//same maybe (maybe first a up/down-cast and then side_casts)
}
*/
int	main(void)
{
	Base * unknown = generate();

	delete unknown;
	return 0;
}