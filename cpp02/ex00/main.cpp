#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	b.setRawBits(10);
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	c.setRawBits(1 << 8);
	std::cout << c.getRawBits() << std::endl;
	return 0;
}