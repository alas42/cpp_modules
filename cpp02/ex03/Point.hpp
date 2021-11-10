#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		~Point(void);
		Point(Point const &point);
		Point(Fixed const x, Fixed const y);
		Point&		operator = (Point const &other);
		bool		bsp(Point const a, Point const b, Point const c, Point const point);
		Fixed const getx(void) const;
		Fixed const gety(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
