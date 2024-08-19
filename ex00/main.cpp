#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>

void testConversion(const std::string& str) {
    char ch;
    int i;
    float f;
    double d;

    std::istringstream ss(str);

    // Convert to double
    // ss.str(str);
    // ss.clear();
    ss >> d;

    std::cout << "String: \"" << str << "\" to double: ";
    if(ss.fail())
        std::cout << "Conversion failed";
    else
        std::cout << std::setprecision(17) << d;
    std::cout << std::endl;

    // Convert to char
    ss.str(str);
    ss.clear();
    ss >> ch;
    std::cout << "String: \"" << str << "\" to char: ";
    if (ss.fail())
        std::cout << "Conversion failed";
    else
    {
        if (32 <= ch && ch <= 126)
            std::cout << ch;
        else
            std::cout << "It's a non-printable variable";
    }
    std::cout << std::endl;

    // Convert to int
    ss.str(str);
    ss.clear();
    ss >> i;
    std::cout << "String: \"" << str << "\" to int: ";
    if (ss.fail())
        std::cout << "Conversion failed";
    else
        std::cout << i;
    std::cout << std::endl;

    // Convert to float
    ss.str(str);
    ss.clear();
    ss >> f;
    std::cout << "String: \"" << str << "\" to float: ";
    if (ss.fail())
        std::cout << "Conversion failed";
    else
        std::cout << std::setprecision(17) << f;
    std::cout << std::endl;

}

int main()
{

    std::string testStrings[] = {"あ","a","A","1.12","1.1234567890","0", "nan", "inff", "inf"};

    for (size_t i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); ++i) {
        const std::string& str = testStrings[i];
        testConversion(str);
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}