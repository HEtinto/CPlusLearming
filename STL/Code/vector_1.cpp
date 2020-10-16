/*
This code will tell you how to use the vector to output and input.
In this code, I use the sort() function,push_back()function and std::getline().
Writing by yujianming 2020/10/16
*/

#include <iostream>
#include <vector>
#include <string>

struct Review
{
    /* data */
    std::string title;
    int rating;
};

bool FillReview(Review & rr)
{
    std::cout << "enter book title (quit to quit):";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
    {
        return false;
    }
    return true;
}

int main()
{
    using std::vector;
    vector<int> number;
    for(int i = 0; i < 5; i++)
    {
        int j;
        std::cin >> j;
        number.push_back(j);
    }
    for(int i=0; i<5; i++)
    {
        std::cout << number[i] << "\t";
    }
    std::cout << "\t";
    std::string s1;
    std::getline(std::cin, s1);
    while(s1 != "quit")
    {
        std::sort(number.begin(), number.end());
            for(int i=0; i<5; i++)
    {
        std::cout << number[i] << "\t";
    }
        std::getline(std::cin, s1);

    }

    return 0;
}