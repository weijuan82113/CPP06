#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copyClass);
		virtual Animal& operator=(const Animal& other);
		virtual void makeSound() const;
		std::string getType() const;
	protected:
		std::string type_;

	private:


};
#endif