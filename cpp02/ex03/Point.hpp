#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		/*
		** Canonical form
		*/
		Point(void);
		~Point(void);
		Point(Point const &point);

		/*
		** Other constructor
		*/
		Point(Fixed const x, Fixed const y);
		
		/*
		** Operators overloads
		*/
		Point&		operator = (Point const &other);
		
		/*
		** Setters and guetters
		*/
		Fixed const getx(void) const;
		Fixed const gety(void) const;

		/*
		** Misc
		*/
		bool		bsp(Point const a, Point const b, Point const c, Point const point);

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
