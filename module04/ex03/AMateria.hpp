#ifndef AMATERIA_HPP_
 #define AMATERIA_HPP_

#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
	protected :
		std::string type_;
	public :
		AMateria(std::string const & type);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};


#endif