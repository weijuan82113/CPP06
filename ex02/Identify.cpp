#include "Identify.h"

const int Identify::base_num = 3;
Identify::Initializer Initializer;


void Identify::initailize_rand() {
	std::srand(static_cast<unsigned int>(time(0)));
}

Base* Identify::generate(void)
{
	//the x is random num betweeen 1 ~ base_num
	int x = base_num + 1;
	while (x > base_num)
		x = 1 + std::rand() / ((RAND_MAX + 1u) / base_num);
	switch(x)
	{
		case 1:
			std::cout << "generate new A" << std::endl;
			return new BaseA();
		case 2:
			std::cout << "generate new B" << std::endl;
			return new BaseB();
		case 3:
			std::cout << "generate new C" << std::endl;
			return new BaseC();
		default:
			return NULL;

	}
}

void Identify::identify(Base* p)
{
	Base* base_ptr[3] = {NULL, NULL, NULL};

	//downcasting
	base_ptr[0] = dynamic_cast<BaseA*>(p);
	base_ptr[1] = dynamic_cast<BaseB*>(p);
	base_ptr[2] = dynamic_cast<BaseC*>(p);

	for(int i = 0; i < base_num; i++)
	{
		if(base_ptr[i] != NULL)
			print_base_type(i);
	}
}

void Identify::print_base_type(int i)
{
	base_type type = static_cast<base_type>(i);
	switch(type)
	{
		case(base_a) :
			std::cout << "identify in ptr cast: A" << std::endl;
			return;
		case(base_b) :
			std::cout << "identify in ptr cast: B" << std::endl;
			return;
		case(base_c) :
			std::cout << "identify in ptr cast: C" << std::endl;
			return;
		default :
			std::cout << "identify in ptr cast: undefine" << std::endl;
			return;
	}
}

void Identify::identify(Base& p)
{
	for(int i = 0; i < base_num; i++)
		try_base_type(i,p);
}

void Identify::try_base_type(int i, Base& p)
{
	base_type type = static_cast<base_type>(i);
	switch(type)
	{
		case(base_a) :
		{
			try
			{
				BaseA& base_ref = dynamic_cast<BaseA&>(p);
				(void)base_ref;
				std::cout << "identify in ref cast: A" << std::endl;
			}
			catch(const std::exception& e) {}
			return;
		}
		case(base_b) :
		{
			try
			{
				BaseB& base_ref = dynamic_cast<BaseB&>(p);
				(void)base_ref;
				std::cout << "identify in ref cast: B" << std::endl;
			}
			catch(const std::exception& e) {}
			return;
		}
		case(base_c) :
		{
			try
			{
				BaseC& base_ref = dynamic_cast<BaseC&>(p);
				(void)base_ref;
				std::cout << "identify in ref cast: C" << std::endl;
			}
			catch(const std::exception& e) {}
			return;
		}
		default :
			std::cout << "identify in ref cast: undefine" << std::endl;
			return;
	}
}

