# This article will tell you how to use to for() base on the range. 
## show the code about how to use the for() base on the range. 
```C++
    double prices[5] = {4.1, 6.7, 3.8, 9.9, 1.2};
    for (double x : prices)
    {
        cout << x << std::endl;
    }
```
## the optimize write is as follows: 
```C++
    for (auto x : prices)
    {
        cout << x << std::endl;
    }
```