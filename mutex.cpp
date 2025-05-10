#include <iostream>
#include <map>
#include <thread>
#include <mutex>

std::map<std::string, bool> pool;
std::mutex m;

void pushUrl(const std::string& url, bool b)
{
   std::lock_guard<std::mutex> lock(m);
   pool[url] = b;
}

int main()
{
    std::thread t1(pushUrl, "www.sina.com.cn", true);
    std::thread t2(pushUrl, "www.google.com", false);
    t1.join();
    t2.join();
    for (auto e : pool) {
       std::cout << e.first  << " " << e.second << std::endl;
    }
    return 0;
}
