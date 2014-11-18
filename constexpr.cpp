#include <iostream>

constexpr int triple(int x)
{
    // 1. Can not modify x
    // 2. Must return value
    // 3. Can not modify variable outside the function
    return (x << 1) + x;
}

int main()
{
    const int x = 1000;
    // x must be constant
    constexpr int y = triple(x);
    std::cout << y  << std::endl;
    return 0;
}
