### vector 是一个可以存放任意类型的动态数组，能够增加和压缩数据

### 1. 声明和初始化
头文件 #include <vector>

构造函数
```cpp
vector<T>    v1;        //vevtor保存类型为T的对象。默认构造函数v1为空。
vector<T>    v2(v1);        //v2是v1的一个副本，v1和v2的元素类型必须相同
vector<T>    v3(n,i);        //v3包含n个值为i的元素
vector<T>    v4(n);            //v4包含初始化的元素的n个副本，默认元素值为0
```

### 2. 常用操作
```cpp
v.empty();        //如果v为空，则返回true，否则返回false
v.size();            //返回v中元素的个数
v.push_back(t);          //在v的末尾添加一个值为t的元素
v[n];                //返回v中位置为n的元素，从0开始计数
v1=v2;            //把v的内容替换为v2的一个副本
v1==v2;            //比较v1和v2的内容,相等则返回true，否则返回false
!=,<,<=,>和>=　　　　//保持这些操作符惯有的含义
```
### 3. vector 迭代

```cpp
vector<int> v;
vector<int>::iterator it;  //定义正向迭代器
for(it = v.begin(); it != v.end(); it++)
  cout << *it << endl;

vector<int>::reverse_iterator it; //定义反向迭代器
for(it = v.rbegin(); it != v.rend(); it++)
  cout << *it << endl;
```
### 4. 再复制点
```cpp
1.vector的初始化：可以有五种方式,举例说明如下：

（1） vector<int> a(10); //定义了10个整型元素的向量（尖括号中为元素类型名，它可以是任何合法的数据类型），但没有给出初值，其值是不确定的。
（2）vector<int>a(10,1); //定义了10个整型元素的向量,且给出每个元素的初值为1
（3）vector<int>a(b); //用b向量来创建a向量，整体复制性赋值
（4）vector<int>a(b.begin(),b.begin+3); //定义了a值为b中第0个到第2个（共3个）元素
（5）int b[7]={1,2,3,4,5,9,8};vector<int> a(b,b+7); //从数组中获得初值

2.vector对象的几个重要操作，举例说明如下：

（1）a.assign(b.begin(), b.begin()+3);//b为向量，将b的0~2个元素构成的向量赋给a
（2）a.assign(4,2);//是a只含4个元素，且每个元素为2
（3）a.back();//返回a的最后一个元素
（4）a.front();//返回a的第一个元素
（5）a[i]; //返回a的第i个元素，当且仅当a[i]存在
（6）a.clear();//清空a中的元素
（7）a.empty();//判断a是否为空，空则返回ture,不空则返回false
（8）a.pop_back();//删除a向量的最后一个元素
（9）a.erase(a.begin()+1,a.begin()+3);//删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+3（不包括它）
（10）a.push_back(5);//在a的最后一个向量后插入一个元素，其值为5
（11）a.insert(a.begin()+1,5);//在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
（12）a.insert(a.begin()+1,3,5);//在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
（13）a.insert(a.begin()+1,b+3,b+6);//b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8，插入元素后为1,4,5,9,2,3,4,5,9,8
（14）a.size();//返回a中元素的个数；
（15）a.capacity();//返回a在内存中总共可以容纳的元素个数
（16）a.rezize(10);//将a的现有元素个数调至10个，多则删，少则补，其值随机
（17）a.rezize(10,2);//将a的现有元素个数调至10个，多则删，少则补，其值为2
（18）a.reserve(100);//将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才 显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能） 
（19）a.swap(b);//b为向量，将a中的元素和b中的元素进行整体性交换
（20）a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
```
举例说明
```cpp
1、向向量a中添加元素

vector<int> a;
for(int i=0;i<10;i++)
a.push_back(i);
```
```cpp
2、也可以从数组中选择元素向向量中添加

int a[6]={1,2,3,4,5,6};
vector<int> b；
for(int i=1;i<=4;i++)
b.push_back(a[i]);
```
```cpp
3、也可以从现有向量中选择元素向向量中添加
int a[6]={1,2,3,4,5,6};
vector<int> b;
vector<int> c(a,a+4);
for(vector<int>::iterator it=c.begin();it<c.end();it++)
b.push_back(*it);
```
```cpp
4、也可以从文件中读取元素向向量中添加

ifstream in("data.txt");
vector<int> a;
for(int i; in>>i)
a.push_back(i);
```
```cpp
5、易犯错误

vector<int> a;
for(int i=0;i<10;i++)
a[i]=i;
//这种做法以及类似的做法都是错误的。下标只能用于获取已存在的元素，而现在的a[i]还是空的对象
```
```cpp
### 5. 注意
```cpp
使用vector需要注意以下几点：

1、如果你要表示的向量长度较长（需要为向量内部保存很多数），容易导致内存泄漏，而且效率会很低；

2、Vector作为函数的参数或者返回值时，需要注意它的写法：

   double Distance(vector<int>&a, vector<int>&b) 其中的“&”绝对不能少！！！
```
### 6. vector 二维数组
```cpp
vector<vector<int>> array(5);
for(int i = 0; i < array.size(); i++)
  array[i].resize(3);
for(int i = 0; i < array.size(); i++)
  for(int j = 0; j < array[0].size(); j++)
    array[i][j] = 1;
for(int i = 0; i < array.size(); i++)
  array[i[.push_back(n);
  ```
