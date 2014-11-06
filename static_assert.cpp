#include <iostream>
#include <string>
#include <type_traits>

template <typename  T>
T concat(const T& a, const T& b)
{
    static_assert( not std::is_integral<T>::value, "Integer is invalid"); 
    return a + " " + b;
}


int main()
{
   // Will trigger compile error
   std::cout << concat<int>(10, 20) << std::endl; 
   std::cout << concat<std::string>("abc", "ef") << std::endl;
   return 0;
}
