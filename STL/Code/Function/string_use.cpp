// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand


int main () 
{
    using std::string;
    string s1 = "hello";
    string s2 = "world";
    string s;
    s.append(&s1[1], 2);
    std::cout << s << "\n";
    return 0;
}