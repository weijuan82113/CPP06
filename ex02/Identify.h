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
		enum base_type
		{
			base_a = 0,
			base_b = 1,
			base_c = 2,
		};

		Base* generate(void);
		void identify(Base* p);
		void identify(Base& p);

		// Static initializer class
		class Initializer {
			public:
				Initializer(){
					initailize_rand();
				}
		};
	private:
		static void initailize_rand();
		static void print_base_type(int i);
		static void try_base_type(int i, Base& p);
		static const int base_num;
};

#endif