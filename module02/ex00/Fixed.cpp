#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& copy_class)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = copy_class._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		_value = other._value;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
};

int getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
};

void setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
};
