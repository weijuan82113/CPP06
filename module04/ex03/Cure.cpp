
#include "Cure.hpp"

Cure::Cure():AMateria()
{
	this->type_ = "Cure";
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "<Cure> constructor" << std::endl;
	if (this != &other)
	{
		this->type_ = other.type_;
	}
}

Cure* Cure::clone() const
{
	Cure* clone = new Cure();
	*clone = *this;
}
