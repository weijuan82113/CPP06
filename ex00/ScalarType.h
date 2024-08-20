#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

class ScalarType
{
	public:
		std::string convertToChar(const std::string& str) const;
		std::string convertToInt(const std::string& str) const;
		std::string convertToFloat(const std::string& str) const;
		std::string convertToDouble(const std::string& str) const;
	private:
		bool isNan(const std::string& str) const;
		static bool isInf(const std::string& str);
		static bool isInfStr(const std::string& str);
};

