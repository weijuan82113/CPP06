#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
void testConversion(const std::string& str) {
    char ch;
    // int i;
    // float f;
    // double d;

    std::stringstream ss(str);

    // Convert to char
    // ss.str(str);
    ss.clear();
    ss >> ch;
    std::cout << "String: \"" << str << "\" to char: ";
    if (ss.fail())
        std::cout << "Conversion failed";
    else
    {
        std::stringstream ssc;
        ssc.clear();
        ssc << ch;
        std::cout << "for stringstream convert : "<< ssc.str() << "\n";
        std::cout << "for straight convert : "<< ch;
    }
    std::cout << std::endl;

    // // Convert to int
    // ss.str(str);
    // ss.clear();
    // ss >> i;
    // std::cout << "String: \"" << str << "\" to int: ";
    // if (ss.fail())
    //     std::cout << "Conversion failed";
    // else
    // {
    //     std::stringstream ssi;
    //     ssi.clear();
    //     ssi << i;
    //     std::cout << "for stringstream convert : "<< ssi.str() << "\n";
    //     std::cout << "for straight convert : "<< i;
    // }
    // std::cout << std::endl;

    // // Convert to float
    // ss.str(str);
    // ss.clear();
    // ss >> f;
    // std::cout << "String: \"" << str << "\" to float: ";
    // if (ss.fail())
    //     std::cout << "Conversion failed";
    // else
    // {
    //     std::stringstream ssf;
    //     ssf.clear();
    //     ssf << f;
    //     std::cout << "for stringstream convert : " << std::setprecision(17) << ssf.str() << "\n";
    //     std::cout << "for straight convert : " << std::setprecision(17) << f;
    // }
    // std::cout << std::endl;

    // // Convert to double
    // ss.str(str);
    // ss.clear();
    // ss >> d;

    // std::cout << "String: \"" << str << "\" to double: ";
    // if(ss.fail())
    //     std::cout << "Conversion failed";
    // else
    // {
    //     std::stringstream ssd;
    //     ssd.clear();
    //     ssd << d;
    //     std::cout << "for stringstream convert : " << std::setprecision(17) << ssd.str() << "\n";
    //     std::cout << "for straight convert : " << std::setprecision(17) << d;
    // }
    // std::cout << std::endl;
}

int main()
{
    std::string testStrings[] = {" ","0.001", "abc", "nan", "inff", "inf", "-inff", "-inf"};

    for (size_t i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); ++i) {
        const std::string& str = testStrings[i];
        testConversion(str);
        std::cout << "------------------------" << std::endl;
    }
    return 0;
}
