#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

template < typename T = int>
class MutantStack: public std::stack<T>
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
		MutantStack<T>(MutantStack<T> const & other)
		{
			*this = other;
		}
		MutantStack<T> & operator = (MutantStack<T> const & other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return (*this);
		}

		/*
		** Misc
		*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack<T>::iterator begin()
		{
			return this->c.begin();
		}
		MutantStack<T>::iterator end()
		{
			return this->c.end();
		}
};

#endif
