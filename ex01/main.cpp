#include "Serialize.h"

int main()
{
	Data d("wchen", 18);
	Serialize sl;

	std::cout << "------ before serialize ------" << std::endl;

	//show deserialized data's ptr
	std::cout << "data ptr: "<< &d << std::endl;
	//show data's name & age
	std::cout << "the data name: "
	<< d.getName() << "\n"
	<< "the data age: "
	<< d.getAge() << std::endl;

	std::cout << "------ before serialize ------\n\n" << std::endl;



	std::cout << "------ serialize ------" << std::endl;

	uintptr_t data_to_uint = sl.serialize(&d);
	std::cout << "uint: "<< data_to_uint << std::endl;

	std::cout << "------ serialize ------\n\n" << std::endl;



	std::cout << "------ after deserialize ------" << std::endl;

	Data *uint_to_data_ptr = sl.deserialize(data_to_uint);
	//show deserialized data's ptr
	std::cout << "data ptr: "<< uint_to_data_ptr << std::endl;
	//show deserialized data's name & age
	std::cout << "the deserialize data name: "
	<< uint_to_data_ptr->getName() << "\n"
	<< "the deserialize data age: "
	<< uint_to_data_ptr->getAge() << std::endl;

	std::cout << "------ after deserialize ------" << std::endl;
}