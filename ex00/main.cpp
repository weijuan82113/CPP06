#include "ScalarType.h"

bool ft_isPrintable(const std::string &str)
{
	const char* str_ptr = str.c_str();
	while (*str_ptr)
	{
		if (*str_ptr < 33 || *str_ptr > 126)
			return false;
		str_ptr ++;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Please intput one variable, like: ./convert <variable>" << std::endl;
		return 1;
	}
	const std::string str(argv[1]);
	if (!ft_isPrintable(str))
	{
		std::cout << "Please intput printable ASCII code" << std::endl;
		return 1;
	}
	ScalarType converter;
	//convert各データ型の関数を実行する
	for(int i = 0 ; i < 4; i ++)
	{
		switch (i) {
			case 0:
			{
				std::cout << "char: ";
				std::cout << converter.convertToChar(argv[1]) << std::endl;
				break;
			}
			case 1:
			{
				std::cout << "int: ";
				std::cout << converter.convertToInt(argv[1]) << std::endl;
				break;
			}
			case 2:
			{
				std::cout << "float: ";
				std::cout << converter.convertToFloat(argv[1]) <<std::endl;
				break;
			}
			case 3:
			{
				std::cout << "double: ";
				std::cout << converter.convertToDouble(argv[1]) <<std::endl;
				break;
			}
			default:
				break;
		}
	}

	return 0;
}
