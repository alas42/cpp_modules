#ifndef ITER_HPP
# define ITER_HPP

template < typename T>
void print_elem(T const & elem)
{
	std::cout << elem << std::endl;
}

template < typename T >
void	iter(T array_ptr[], int length, void (*func)(T const & ))
{
	for (int i = 0; i < length; i++)
	{
		func(array_ptr[i]);
	}
}

#endif
