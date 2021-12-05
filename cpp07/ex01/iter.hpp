#ifndef ITER_HPP
# define ITER_HPP

template < typename T >
void	iter(T * array_ptr, size_t & length, T ::*func(T))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array_ptr[i]);
	}
};

#endif
