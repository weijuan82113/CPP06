#include "Ice.hpp"

Ice::Ice():AMateria()
{
	this->type_ = "ice";
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "<Ice> constructor" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
}

Ice* Ice::clone() const
{
	Ice* clone = new Ice();
	*clone = *this;
}
