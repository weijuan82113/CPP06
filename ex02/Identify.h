#ifndef IDENTIFY_H_
 #define IDENTIFY_H_

#include "Base.h"
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
		static initailize_rand();
};

#endif