#include "ScalarType.h"

ScalarType::ScalarType() {}
ScalarType::~ScalarType() {}
ScalarType::ScalarType(ScalarType& s) {(void)s;}
ScalarType& ScalarType::operator=(ScalarType& d) {(void)d;return *this;}

std::string ScalarType::convertToChar(const std::string &str) const
{
	std::stringstream ss;
	ss << str;
	int ss_to_i;
	ss >> ss_to_i;

	//1 charactor assci code && not number
	if (str.length() == 1 && !isInt(str))
		return str;
	if (ss.fail() || !isInt(str))
		return "impossible";
	if (ss_to_i < 33 || ss_to_i > 126)
		return "Non displayable";
	char ret_ch = static_cast<char>(ss_to_i);
	ss.str("");
	ss.clear();
	ss << ret_ch;
	ss.str();
	return "'" + ss.str() + "'";
}

std::string ScalarType::convertToInt(const std::string& str) const
{
	std::stringstream ss;
	ss << str;
	int ss_to_i;
	ss >> ss_to_i;
	int ret_int = 0;

	//1文字 ascci code charactor & not number
	if (str.length() == 1 && !isInt(str))
	{
		ret_int = static_cast<int>(*str.c_str());
		ss.str("");
		ss.clear();
		ss << ret_int;
		return ss.str();
	}
	//ss_to_i failed && !(s13e10 or number)
	else if (ss.fail() || !isInt(str))
		return "impossible";
	ss.str("");
	ss.clear();
	//小数の場合は、ここで一度ss_to_iで切り捨てられた整数を再度ssに代入する
	ss << ss_to_i;
	return ss.str();
}

std::string ScalarType::convertToFloat(const std::string& str) const
{
	std::stringstream ss;
	ss << str;
	float ss_to_f;
	ss >> ss_to_f;
	float ret_float = 0.0f;

	//"ss_to_float successful"
	if (!ss.fail())
	{
		//std::cout << "ss_to_float successful" << std::endl;
		ss.str("");
		ss.clear();
		ss << std::setprecision(8) << ss_to_f;
		return isInteger(ss_to_f) ? ss.str() + ".0f" : ss.str() + "f";
	}
	else if (isNan(str))
	{
		//std::cout << "str is nan" << std::endl;
		ret_float = std::numeric_limits<float>::quiet_NaN();
	}
	// ask how to do more simpler if expression
	else if (isInf(str))
	{
		ret_float = *str.c_str() == '-' ?
		-std::numeric_limits<float>::infinity() :
		std::numeric_limits<float>::infinity();
	}
	// 1文字、ascii code
	else if (str.length() == 1)
		ret_float = static_cast<float>(*str.c_str());
	else if (str.length() > 5 || !isInf(str))
		return "impossible";
	ss.str("");
	ss.clear();
	ss << std::setprecision(8) << ret_float;
	return ss.str() + "f";
}

std::string ScalarType::convertToDouble(const std::string& str) const
{
	std::stringstream ss;
	ss << str;
	double ss_to_d;
	ss >> ss_to_d;
	double ret_double = 0.0;

	//ss_to_double successful
	if (!ss.fail())
	{
		// std::cout << "ss_to_double successful" << std::endl;
		ss.str("");
		ss.clear();
		ss << std::setprecision(16) << ss_to_d;
		return isInteger(ss_to_d) ? ss.str() + ".0" : ss.str();
	}
	else if (isNan(str))
	{
		//std::cout << "str is nan" << std::endl;
		ret_double = std::numeric_limits<double>::quiet_NaN();
	}
	// ask how to do more simpler if expression
	else if (isInf(str))
	{
		ret_double = *str.c_str() == '-' ?
		-std::numeric_limits<double>::infinity() :
		std::numeric_limits<double>::infinity();
	}
	// 1文字、ascii code
	else if (str.length() == 1)
		ret_double = static_cast<double>(*str.c_str());
	else if (str.length() > 5 || !isInf(str))
		return "impossible";
	ss.str("");
	ss.clear();
	ss << std::setprecision(16) << ret_double;
	return ss.str();
}

bool ScalarType::isNan(const std::string &str) const
{
	const char *str_ptr = str.c_str();
	int i = 0;
	while (*str_ptr)
	{
		if (i == 0 && !(*str_ptr == 'N' || *str_ptr == 'n'))
			return false;
		else if (i == 1 && !(*str_ptr == 'A' || *str_ptr == 'a'))
			return false;
		else if (i == 2 && !(*str_ptr == 'N' || *str_ptr == 'n'))
			return false;
		else
			str_ptr ++;
		i++;
	}
	if (i == 3)
		return true;
	return
		false;
}

bool ScalarType::isInf(const std::string& str)
{
	// <+,-><inff,inf>
	if (isInfStr(str))
		return true;
	return
		false;
}

bool ScalarType::isInfStr(const std::string& str)
{
	if (str == "inff")
		return true;
	else if (str == "+inff")
		return true;
	else if (str == "-inff")
		return true;
	else if (str == "inf")
		return true;
	else if (str == "+inf")
		return true;
	else if (str == "-inf")
		return true;
	else
		return false;
}

bool ScalarType::isInt(const std::string& str)
{
	const char* str_ptr = str.c_str();
	while(*str_ptr)
	{
		//!number && !(the expressin with alphabet like: 1.0,10e10)
		if ((*str_ptr < '0' || *str_ptr > '9') &&
		!(*str_ptr == '.' || *str_ptr == 'e' || *str_ptr == 'f' || *str_ptr == '+' || *str_ptr == '-'))
			return false;
		str_ptr ++;
	}
	return true;
}