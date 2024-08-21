#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>

class Person {
public:
    std::string name;
    int age;

    void serialize(std::ostream& os) const {
        os << name << ' ' << age;
    }

    void deserialize(std::istream& is) {
        is >> name >> age;
    }
};

int main()
{

	//uintptr_t uint_ptr;

	//test serialize
	Person person;
	std::stringstream ss;

	ss.str("");
	ss.clear();
	person.serialize(ss);
	person.deserialize(ss);

	
	std::cout << "ss:" << ss.str() << std::endl;
	std::cout << "name:" << person.name << std::endl;
	std::cout << "age" << person.age << std::endl;


}