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
		~MutantStack<T>(void){}
		MutantStack<T>(MutantStack<T> const & other)
		{
			*this = other;
		}
		MutantStack<T> & operator = (MutantStack<T> const & other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
				this->c = other.c;
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

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		MutantStack<T>::reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}
		MutantStack<T>::reverse_iterator rend()
		{
			return this->c.rend();
		}
};

#endif
