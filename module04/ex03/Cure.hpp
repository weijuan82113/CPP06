#ifndef CURE_HPP_
 #define CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria
{
	Cure();
	Cure& operator=(const Cure& other);
	Cure* clone() const;

};

#endif