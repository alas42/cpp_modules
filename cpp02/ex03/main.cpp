#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main(void)
{

	Fixed	a0x(453), a0y(328), a1x(115), a1y(12), a2x(413), a2y(19);
	/*Fixed	b0x, b0y, b1x, b1y, b2x, b2y;
	Fixed	c0x, c0y, c1x, c1y, c2x, c2y;*/

	Point	a0(a0x, a0y), a1(a1x, a1y), a2(a2x, a2y);
	/*Point	b0(b0x, b0y), b1(b1x, b1y), b2(b2x, b2y);
	Point	c0(c0x, c0y), c1(c1x, c1y), c2(c2x, c2y);*/

	std::cout << "p0(x) : " << a0.getx() << " p0(y) : " << a0.gety()
		<< "\np1(x) : " << a1.getx() << " p1(y) : " << a1.gety()
		<< "\np2(x) : " << a2.getx() << " p2(y) : " << a2.gety() << std::endl;

	Fixed	is_inx(73), is_iny(25);
	Point	is_in(is_inx, is_iny);
	if (is_in.bsp(a0, a1, a2, is_in))
		std::cout << "It's in the triangle" << std::endl;
	else
		std::cout << "It's not in the triangle" << std::endl;
	return 0;
}