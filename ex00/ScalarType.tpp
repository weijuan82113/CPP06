#ifndef SCALARTYPE_TPP
#define SCALARTYPE_TPP

#include <cmath>

template <typename T>
bool isInteger(T value) {
    return std::floor(value) == value;
}

#endif