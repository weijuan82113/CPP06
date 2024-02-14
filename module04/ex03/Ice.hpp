#ifndef ICE_HPP_
 #define ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria
{
	Ice();
	Ice& operator=(const Ice& other);
	Ice* clone() const;

};

#endif