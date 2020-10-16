# STL函数 
## for_each()函数 
&ensp;&ensp;for_each()函数是指向函数的指针（更普遍地说，最后一个参数是一个函数对象）。for_each()函数将被指向的函数应用于容器区间的各个元素。被指向的函数不能修改容器元素的值。 

&ensp;&ensp;可以用for_each()函数来代替for循环。例如： 

&ensp;&ensp;可以将如下代码：
```C++
    vector<Review>::iterator pr;
    for (pr=book.begin(); pr!=book.end(); pr++)
    {
        ShowReview(*pr);
    }
``` 

&ensp;&ensp;替换为： 
```C++
for_each(books.begin(), books.end(), ShowReview);
``` 

&ensp;&ensp;这样可以避免显式地使用迭代器变量。 
## random_shuffle() 
&ensp;&ensp;random_shuffle()函数接受两个指定区间的迭代器参数，并随机排列该区间中的元素。同时，该函数要求容器支持随机访问。 

&ensp;&ensp;例如，下面的语句随机排列books矢量中所有元素： 
```C++
    random_shuffle(books.begin(), books.end());
``` 

&ensp;&ensp;从上面的例子可以看出：random_shuffle()函数的第一个参数为区间的起点，第二个参数是区间的终点的下一个节点。 
## sort()函数 
&ensp;&ensp;sort()函数要求容器支持随机访问。该函数有两个版本，第一个版本接受两个定义区间的迭代器参数，并使用为存储在容器中的类型元素定义的``<``运算符，对区间中的元素进行操作。 

&ensp;&ensp;例如，下面的语句按升序对coolstuff的内容进行排序，排序时使用内置的``<``运算符，对区间中的元素进行操作。例如，下面的语句按升序对coolstuff的内容进行排序，排序时使用内置的``<``运算符对值进行比较：
```C++
    vector<int> coolstuff;
    ......
    sort(coolstuff.begin(), coolstuff.end());
``` 

&ensp;&ensp;如果容器是用户定义的对象，则要使用sort()，必须定义能够处理该类型对象的``operator<()``函数。 

&ensp;&ensp;例如，如果为Review提供了成员或非成员函数``operator < ()``，则可以对包含Review对象的矢量进行排序。 

&ensp;&ensp;由于Review是一个结构体，因为其成员是默认公有的，这样的非成员函数将为： 
```C++
    bool operator < (const Review & r1, const Review & r2)
    {
        if (r1.title < r2.title)
        return true;
        else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
        else 
        return false;
    }
``` 
&ensp;&ensp;有了这样的函数后，就可以对包含Review对象（如books）的矢量进行排序：
```C++
    sort(books.begin(), books.end());
``` 

&ensp;&ensp;**另一种格式的sort()。**它接受三个参数，前两个参数也是指定区间的迭代器，最后一个参数也是指定区间的迭代器，最后一个参数是指向要使用的函数的指针（函数对象），而不是用于比较的``operator < ()``。 

&ensp;&ensp;返回值可以转换为``bool``，``false``表示两个参数的顺序不正确。下面是一个例子：
``` C++
    bool WorseThan(const Review & ri, const Review & r2)
    {
        if (r1.rating < r2.rating>)
        return true;
        else
        return false;
    }
``` 
&ensp;&ensp;有了这个函数，就可以使用下面的语句将包含Review对象的books矢量按rating升序排列：
```C++
    sort(books.begin(), books.end(), WorseThan);
```