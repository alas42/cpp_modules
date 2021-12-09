#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <vector>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Span
{
	class AlreadyFullException: public std::exception
	{
		public:
			const char * what() const throw();
	};
	class NoSpanToFindException: public std::exception
	{
		public:
			const char * what() const throw();
	};

	public:
		/*
		** Canonical Form
		*/
		Span(void);
		~Span(void);
		Span(Span const & other);
		Span & operator = (Span const & other);

		/*
		** Other constructor
		*/
		Span(unsigned int N);

		/*
		** Misc
		*/
		void						addNumber(int new_number);
		void						addNumberRange(int * begin, int * end);
		int							shortestSpan(void);
		int							longestSpan(void);

		/*
		** Guetter
		*/
		std::vector<int> const &	getVector(void) const;

	private:
		unsigned int		_max_size;
		std::vector<int>	_vector;
};

#endif
