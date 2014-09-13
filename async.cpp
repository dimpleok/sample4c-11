// c++ -std=c++0x async.cpp -lpthread
#include <future>
#include <iostream>
#include <unistd.h>
#include <chrono>

int fun(int x)
{
   std::this_thread::sleep_for( std::chrono::seconds(3) );
   return x*x;
}

int main()
{
   //auto f = std::async( fun, 10);
   std::future<int> f = std::async(fun, 10);
   std::cout << "wait result..." << std::endl;
   std::cout << f.get() << std::endl;
   return 0;
}
