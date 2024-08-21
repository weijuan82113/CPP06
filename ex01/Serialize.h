#ifndef SERIALIZE_H_
 #define SERIALIZE_H_

#include <stdint.h>
#include <string>
#include <sstream>
#include <iostream>
#include "Data.h"

class Serialize
{
	public:
		uintptr_t serialize(Data *ptr);
		Data* deserialize(uintptr_t raw);
};

#endif