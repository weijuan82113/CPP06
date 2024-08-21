#include "Data.h"

// Default constructor
Data::Data() : name_(""), age_(0) {}

//Constructor with name & age
Data::Data(std::string name, int age) : name_(name), age_(age) {}

// Destructor
Data::~Data() {}

// Copy constructor
Data::Data(Data &d) : name_(d.name_), age_(d.age_) {}

// Assignment operator
Data& Data::operator=(Data &d){
	if (this == &d) {
		return *this;
	}
	name_ = d.name_;
	age_ = d.age_;
	return *this;
}

// Get the name
std::string Data::getName() {
	return name_;
}

// Get the age
int Data::getAge() {
	return age_;
}