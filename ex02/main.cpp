#include "Identify.h"

int main()
{
	Identify id;
	std::cout << "----test---" << std::endl;
	Base* b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b = id.generate();
	id.identify(b);
	id.identify(*b);
	std::cout << "----test---" << std::endl;
	b->~Base();
	//dynamic_casr;
	return 0;
}