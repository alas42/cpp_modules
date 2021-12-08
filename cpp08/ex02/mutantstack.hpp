#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <deque>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

template < typename T >
class MutantStack: public std::deque<T>
{
	public :
		/*
		** Canonical Form
		*/
		MutantStack<T>(void)
		{
			std::cout << GREEN << "A MutantStack has been created " << RESET << std::endl;
		}
		~MutantStack<T>(void)
		{
			std::cout << RED << "A MutantStack has been deleted" << RESET << std::endl;
		}
		MutantStack<T>(MutantStack const & other)
		{
			*this = other;
		}
		MutantStack<T> & operator = (MutantStack<T> const & other)
		{
			if (!(this == &other))
			{
				std::deque<T>::operator=(other);
			}
			return (*this);
		}
		/*
		** Misc
		*/
		void	push(T const & thing)
		{
			this->push_back(thing);
		}

		void	pop(void)
		{
			this->pop_back();
		}

		T &		top(void)
		{
			return this->back();
		}
};

#endif
