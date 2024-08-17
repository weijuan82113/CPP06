#include <iostream>
#include <limits>

int main()
{
	//型確認
	double positive_infinity = std::numeric_limits<double>::infinity();
    double negative_infinity = -positive_infinity;
    double nan_value = std::numeric_limits<double>::quiet_NaN();

    std::cout << positive_infinity << std::endl; // 出力: inf
    std::cout << negative_infinity << std::endl; // 出力: -inf
    std::cout << nan_value << std::endl;         // 出力: nan

	//inffとinfの違い
	float f_infinity = std::numeric_limits<float>::infinity();  // floatの正の無限大
    double d_infinity = std::numeric_limits<double>::infinity(); // doubleの正の無限大

    float f_var = f_infinity;   // float型変数にinffを代入
    double d_var = d_infinity;    // double型変数にinfを代入

    std::cout << f_var << std::endl;  // 出力: inf
    std::cout << d_var << std::endl;  // 出力: inf

    return 0;
}