#ifndef IDENTIFY_H_
 #define IDENTIFY_H_

#include "Base.h"
#include "BaseA.h"
#include "BaseB.h"
#include "BaseC.h"

#include <cstdlib>
#include <ctime>
#include <iostream>



class Identify
{
	public:
		Base* generate(void);
		void identify(Base* p);
		void identify(Base& p);

	private:
		static void print_base_type(int i);
		static void try_base_type(int i, Base& p);
		static void initailize_rand();
		static const int base_num;
		static const int base_a;
		static const int base_b;
		static const int base_c;

};

#endif