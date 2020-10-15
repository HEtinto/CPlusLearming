##   smart pointer

&ensp;&ensp;In sometime,while we use the memory,we may forget to delete it.So we should use the smart to solve this problem. 

&ensp;&ensp;``auto_ptr``,``unique_ptr``and``share_ptr``all define the object like pointer,we can use the ``new``to harvest the address to this smart pointer.The smart pointer use the delete to release the memory. 

&ensp;&ensp;I will show you about the computer how to manage the memory as follows:

```	C++
void demol()
{
  double * pd = new double;  // step1
  *pd = 25.5;  //step2
  return;  //step3
}
```

&ensp;&ensp;In first step,allcate the memory to ``pd``and``double``and save the address.In the second step,put the value to ``pd``.In the third step,will delete the ``pd``,but the value will save in the memory.

&ensp;&ensp;If you want to avoid this problem,the smart pointer will be a good tool.We can use the smart pointer as follows:

```c++
void demo2()
{
  auto_ptr<double> ap(new double);  //step1
  *ap = 25.5;  //step2
  return;  //step3
}
```

&ensp;&ensp;In this code I will show you how to use the smart poibter. 

```c++
#include <iostream>
#include <string>
#include <memory>

namespace error
{
    std::string vacation("I want to fly!!");
    std::shared_ptr<std::string> pvac(&vacation);
}

class Report
{
    private:
    std::string str;
    public:
    Report(const std::string s) : str(s)
    {
        std::cout << "Object created!\n";
    }
    ~Report()
    {
        std::cout << "Object deleted!\n";
    }
    void comment() const {std::cout << str << "\n";}
};

int main()
{
    std::auto_ptr<Report> ps(new Report("using auto_ptr"));
    ps->comment();
    {
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();
    }
    //Report r1("str1");
    return 0;
}
```

&ensp;&ensp;While you run this programming,the terminal will output as follows:

```c++
Object created!
using auto_ptr
Object created!
using shared_ptr
Object deleted!
Object created!
using unique_ptr
Object deleted!
Object deleted!
```

&ensp;&ensp;In nowdays,we already give up the ``auto_ptr``,because the ``auto_ptr``will have some problem to use.It is like that： 

```c++
auto_ptr<string> ps (new string("putting the string！"))；
auto_ptr<string> vocation;
vocation = ps;
```

In this code,if the ``ps`` and ``vocation``is normal pointer,they will point to two same strings.In this time,the programming will try to delete the same object twice. 

&ensp;&ensp;The ``shared_ptr``and``unique_ptr``are use the Ownership model,they will not appear this problem.