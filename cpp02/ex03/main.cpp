#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main(void)
{

	/*
	** Coordinates of the three points of the triangle
	*/
	Fixed	a0x(110), a0y(342), a1x(19), a1y(26), a2x(466), a2y(472);

	Point	a0(a0x, a0y), a1(a1x, a1y), a2(a2x, a2y);

	std::cout << "p0(x) : " << a0.getx() << " p0(y) : " << a0.gety()
		<< "\np1(x) : " << a1.getx() << " p1(y) : " << a1.gety()
		<< "\np2(x) : " << a2.getx() << " p2(y) : " << a2.gety() << std::endl;

	/*
	** Coordinates of the point we wishes to know about
	*/
	Fixed	is_inx(132), is_iny(254);
	Point	is_in(is_inx, is_iny);
	if (is_in.bsp(a0, a1, a2, is_in))
	{
		std::cout << "It's in the triangle" << std::endl;
	}
	else
	{
		std::cout << "It's not in the triangle" << std::endl;
	}
	return 0;
}