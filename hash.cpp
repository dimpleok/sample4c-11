#include <iostream>
#include <functional>
#include <string>
 
template <typename T>
struct myHash {
    size_t operator()(T t) {
        return std::hash<std::string>()(t) + 1000;
    }
};

int main()
{
    std::string str = "Meet the new boss...";
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(str);
 
    std::cout << str_hash << '\n';
    std::cout << myHash<std::string>()(str) << std::endl;
    return 0;
}
