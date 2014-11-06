#include <array>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
   std::array<int, 100> arr;
   arr.fill(99);

   arr[0] = 1;
   std::copy( std::begin(arr), std::end(arr),
              std::ostream_iterator<int>(std::cout, " ")
            );
   std::cout << "\n" << "size=" << arr.size() << std::endl;
   std::cout << arr.front() << std::endl;
   std::cout << arr.back() << std::endl;

   std::array<int, 3> arr2{1, 2, 3};
   arr2[1] *= 10;
   for(auto i : arr2) {
       std::cout << i << " ";
   }
   return 0;
}
