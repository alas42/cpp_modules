#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <stdexcept>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

template < typename T = int >
class Array
{
	class OutOfBoundsException: public std::exception
	{
		char const * what() const throw()
		{
			return ("The index is out of bounds");
		}
	};
	public:
		Array<T>(void): _size(0), _elems(new T[0]){}
		Array<T>(unsigned int size): _size(size), _elems(new T[size]){}
		Array<T>(Array<T> & other):_size(other.size())
		{
			this->_elems = new T[other.size()];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_elems[i] = other[i];
		}
		Array<T> & operator = (Array<T> & other)
		{
			if (this != &other)
			{
				if (this->_elems != 0)
					delete [] this->_elems;
				this->_size = other.size();
				this->_elems = new T[other.size()];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_elems[i] = other[i];
			}
			return *this;
		}
		~Array<T>(void)
		{
			delete [] this->_elems;
		}
		unsigned int size(void) const { return this->_size; }
		T & operator [](unsigned int index)
		{
			if (index >= this->_size)
				throw (OutOfBoundsException());
			return this->_elems[index];
		}

	private:
		unsigned int _size;
		T * _elems;
};

#endif
