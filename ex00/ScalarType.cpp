#include "ScalarType.h"

std::string ScalarType::convertToChar(const std::string &str) const
{
	std::stringstream ss;
	ss << str;
	int ss_to_i;
	ss >> ss_to_i;

	if (ss.fail())
		return "impossible";
	if (ss_to_i < 33 || ss_to_i > 126)
		return "Non displayable";
	//if 3文字の入力　impossible
	char i_to_ch = static_cast<char>(ss_to_i);
	ss.str("");
	ss.clear();
	ss << i_to_ch;

	std::string ret_str = ss.str();
	return "'" + ret_str + "'";
}

std::string ScalarType::convertToInt(const std::string& str) const
{
	std::stringstream ss;
	ss << str;
	int ss_to_i;
	ss >> ss_to_i;

	if (ss.fail())
		return "impossible";
	ss.str("");
	ss.clear();
	ss << ss_to_i;
	std::string ret_str = ss.str();
	return ret_str;
}

std::string ScalarType::convertToFloat(const std::string& str) const
{
	std::stringstream ss;
	ss << str;
	float ss_to_f;
	ss >> ss_to_f;

	//ss_to_float successful
	if (!ss.fail())
	{
		//std::cout << "ss_to_float successful" << std::endl;
		ss.str("");
		ss.clear();
		ss << std::setprecision(8) << ss_to_f;
		return isInteger(ss_to_f) ? ss.str() + ".0f" : ss.str() + "f";
	}
	float ret_float = 0.0f;
	if (isNan(str))
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

	//ss_to_double successful
	if (!ss.fail())
	{
		//std::cout << "ss_to_double successful" << std::endl;
		ss.str("");
		ss.clear();
		ss << std::setprecision(16) << ss_to_d;
		return isInteger(ss_to_d) ? ss.str() + ".0" : ss.str();
	}
	double ret_double = 0.0;
	if (isNan(str))
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
	else if (str.length() > 5 || !isInf(str))
		return "impossible";

	ss.str("");
	ss.clear();
	ss << std::setprecision(8) << ret_double;
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