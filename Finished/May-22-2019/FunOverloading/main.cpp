#include <iostream>
#include "abs.h"

int main()
{    
    std::cout << abs(-5) << "\n";	// 调用abs()的整数版本
    std::cout << abs(-5L) << "\n";	// 调用abs()的长整数版本
    std::cout << abs(3.14) << "\n";	// 调用abs()的浮点版本
    return 0;
}