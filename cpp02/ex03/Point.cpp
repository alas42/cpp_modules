#include "Point.hpp"

Point::Point(void):_x(0), _y(0)
{}

Point::Point(Point const &point):_x(point.getx()), _y(point.gety())
{}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{}

Point::~Point(void)
{}

Fixed const Point::getx(void) const
{	return this->_x; }

Fixed const Point::gety(void) const
{	return this->_y; }


Point& Point::operator = (Point const &other)
{
	std::cout << other.getx() << std::endl;
	return *this;
}

/*
** First step : Get the values that we will be able to modify
** Second step : Compute
** Third step : Profit
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
