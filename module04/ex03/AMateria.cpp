#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{

}

std::string const& AMateria::getType() const
{
	return (type_);
}

void AMateria::use(ICharacter& target)
{
	if (type_ == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	else if (type_ == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;

}