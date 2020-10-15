# 使用vector 
## STL提供的基本方法 
* size()———返回容器中元素数目 
* swap()———交换两个容器的内容 
* begin()————返回一个指向容器中第一个元素的迭代器 
* end()————返回一个表示超过容器尾的迭代器 
* push_back()————将元素添加到矢量末尾 
* erase()————删除矢量中给定区间的元素，需要两个参数 
* insert()————将一个容器指定区间的内容插入到另一个容器的指定位置之前，需要三个参数
## 迭代器 
&ensp;&ensp;迭代器实际上是一个广义指针，可以对迭代器执行对指针执行的操作。如果要声明一个迭代器，可以这样做：
```C++
vector<double>::iterator pd;
vector<double> scores;
//可以执行以下操作：
pd = scores.begin();  //让pd指向scores的第一个元素
*pd = 22.2;  //让pd指向的第一个元素的地址上的值赋为22.3
++pd;  //让pd指向下一个元素
``` 
&ensp;&ensp;在这里，我们可以看到，实际上迭代器有指针的作用，通过迭代器的运用，我们可以访问vector中的各个元素。 
&ensp;&ensp;同时，我们可以通过使用C++自动类型推断这样s做： 
```C++
    //可以不这样做：
    vector<double>::iterator pd = scores.begin();
    //而这样做：
    auto pd = scores.begin();
``` 
&ensp;&ensp;我们可以使用以下方法来显示容器中的内容： 
```C++
    for(pd = scores.begin();pd != score.end(); pd++)
    {
        cout << *pd << endl;
    }
``` 
## erase()方法 
&ensp;&ensp;下述代码删除第一个和第二个元素，erase()方法的第一个参数指向的是区间的起点，第二个参数指向的是终点的下一个元素。 
```C++
    scores.erase(score.begin(), score.begin()+2);  //vector提供了随机访问功能，因此vector类迭代器定义了诸如begin()+2等操作
```