#include "span.hpp"

Span::Span(void): _max_size(10)
{
	std::cout << GREEN << "A Span object has been created" << RESET << std::endl;
}

Span::~Span(void)
{
	this->_vector.clear();
}

Span::Span(Span const & other)
{
	*this = other;
	std::cout << GREEN << "A Span object has been created" << RESET << std::endl;  
}

Span & Span::operator = (Span const & other)
{
	if (this != &other)
	{
		this->_vector.erase(this->_vector.begin(), this->_vector.end());
		this->_vector.assign(other.getVector().begin(), other.getVector().end());
	}
	return *this;
}

Span::Span(unsigned int N): _max_size(N)
{
	std::cout << GREEN << "A Span object has been created with a max_size of "
		<< _max_size << RESET << std::endl;
}

void    Span::addNumber(int new_number)
{
	if (this->_vector.size() < this->_max_size)
		this->_vector.push_back(new_number);
	else
		throw(AlreadyFullException());
}

void    Span::addNumberRange(int * begin, int * end)
{
	if (this->_vector.size() + std::distance(begin, end) <= this->_max_size)
			this->_vector.insert(this->_vector.end(), begin, end);
	else
		throw(AlreadyFullException());
}

int    Span::shortestSpan(void)
{
	if (this->_vector.size() <= 1)
		throw(NoSpanToFindException());
	std::vector<int> copy = this->_vector;
	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator it = copy.begin();
	std::vector<int>::iterator ite = copy.end();
	int shortest_span = *(it + 1) - *it;

	for (std::vector<int>::iterator itf = it + 1; itf != ite; ++itf)
	{
		if (*itf - *(itf - 1) < shortest_span)
			shortest_span = (*itf - *(itf - 1));
	}
	return (shortest_span);
}

int    Span::longestSpan(void)
{
	if (this->_vector.size() <= 1)
		throw(NoSpanToFindException());
	std::vector<int> copy = this->_vector;
	std::sort(copy.begin(), copy.end());
	return (*(copy.end() - 1) - *(copy.begin()));
}

std::vector<int> const &	Span::getVector(void) const
{
	return this->_vector;
}

const char * Span::AlreadyFullException::what() const throw()
{
	return "Error: The Span object is already full!";
}

const char * Span::NoSpanToFindException::what() const throw()
{
	return "Error: There is no span to find!";
}
