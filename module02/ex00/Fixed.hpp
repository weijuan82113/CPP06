#ifndef FIXED_HPP
 #define FIXED_HPP
#include <iostream>

class Fixed
{
	public :
		Fixed();
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed(const Fixed& copy_class);
		Fixed& operator=(const Fixed& other);
	private :
		int	_value;
		static int const _frac_bit = 8;
};



#endif