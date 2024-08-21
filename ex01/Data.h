#ifndef DATA_H_
 #define DATA_H_

#include <string>

class Data
{
	public:
		Data();
		Data(std::string name, int age);
		~Data();
		Data(Data &d);
		Data& operator=(Data &d);

		std::string getName();
		int getAge();
	private:
		std::string name_;
		int age_;
};

#endif