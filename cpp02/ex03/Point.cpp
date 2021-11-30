#include "Point.hpp"

/*
** Canonical form
*/
Point::Point(void):_x(0), _y(0)
{}

Point::Point(Point const &point):_x(point.getx()), _y(point.gety())
{}

Point::~Point(void)
{}
/*
** End of Canonical form
*/

/*
** Other constructors
*/
Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{}
/*
** End of other constructors
*/

/*
** Guetters and Setters
*/
Fixed const Point::getx(void) const
{	return this->_x; }

Fixed const Point::gety(void) const
{	return this->_y; }
/*
** End of Guetters and Setters
*/

/*
** Operators overloads
*/
Point& Point::operator = (Point const &other)
{
	return *this;
}
/*
** End of operators overloads
*/

/*
** Misc
*/
bool	Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	px = point.getx();
	Fixed	py = point.gety();
	Fixed	ax = a.getx();
	Fixed	ay = a.gety();
	Fixed	bx = b.getx();
	Fixed	by = b.gety();
	Fixed	cx = c.getx();
	Fixed	cy = c.gety();

	Fixed	dX = px - cx;
	Fixed	dY = py - cy;
	Fixed	dX21 = cx - bx;
	Fixed	dY12 = by - cy;
	Fixed	del = dY12 * (ax - cx) + dX21 * (ay - cy);
	Fixed	s = dY12 * dX + dX21 * dY;
	Fixed	t = (cy - ay) * dX + (ax - cx) * dY;
	if (del < 0)
		return (s <= 0 && t <= 0 && s + t >= del);
	return (s >= 0 && t >= 0 && s + t <= del);
}
/*
** End of Misc
*/
