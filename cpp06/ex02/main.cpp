#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Base
{
	public:
		virtual ~Base(void){}
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base * generate(void)
{
	std::srand(std::time(0));
	int result = (std::rand()%3) + 1;
	switch (result)
	{
		case 3:
			std::cout << "A was created" << std::endl;
			return new A;
		case 2:
			std::cout << "B was created" << std::endl;
			return new B;
		default:
			std::cout << "C was created" << std::endl;
			return new C;
	}
	return NULL;
}

void	identify(Base * p)
{
	/*
	**  Dynamic cast (the one hat throw errors on run-time, so that we can catch the errors)
	*/
	if (A * a = dynamic_cast<A *>(p))
		std::cout << "The Base * is a A *" << std::endl;
	else if (B * b = dynamic_cast<B *>(p))
		std::cout << "The Base * is a B *" << std::endl;
	else if (C * c = dynamic_cast<C *>(p))
		std::cout << "The Base * is a C *" << std::endl;
	else
		std::cout << "The Base * is nothing I know of" << std::endl;
}

void	identify(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		a.~A();
		std::cout << "The Base reference is from class A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B & b = dynamic_cast<B&>(p);
			b.~B();
			std::cout << "The Base reference is from class B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C & c = dynamic_cast<C&>(p);
				c.~C();
				std::cout << "The Base reference is from class C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int	main(void)
{
	Base * unknown = generate();
	Base & unknown_ref = *unknown;

	identify(unknown);
	identify(unknown_ref);
	delete unknown;
	return 0;
}
