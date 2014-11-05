#include <tuple>
#include <string>
#include <iostream>

template <typename T>
void printTuple(T t)
{
    int size = std::tuple_size<T>::value;
    std::cout << "tuple size " << size << std::endl;
    std::cout << std::get<0>(t) << " " 
              << std::get<1>(t) << " " 
              << std::get<2>(t) << std::endl;
}

int main()
{
    std::tuple<int, std::string, std::string> t1 = std::make_tuple(1, "tom", "1111");
    std::tuple<int, std::string, std::string> t2 = std::make_tuple(2, "jack", "2222");
    printTuple(t1);
    int id;
    std::string name;
    std::string phone;

    std::tie(id, name, phone) = t2;
    std::cout << id << " " << name << " " << phone << std::endl;

    std::tie(std::ignore, name, phone) = t1;
    std::cout << name << " " << phone << std::endl;
    return 0;
}
