Map是STL的一个关联容器，它提供一对一（第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可以称为该关键字的值。 key -- > value ）的数据处理能
力。Map内部自建了一颗红黑树（一种非严格意义上的平衡二叉树），这棵树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的。

### 1. map简介
map是一类关联式容器。它的特点是增加和删除节点对迭代器的影响很小，除了那个操作节点，对其他节点都没有什么影响。对于迭代器来说，可以修改实值，而不能修改key。

### 2. map的功能
* 自动建立 key --> value 的对应。key和value可以是任意需要的类型。
* 根据key值快速查找记录。查找的时间复杂度为 log(N)。
* 快速插入 key -- value 记录。
* 快速删除记录。
* 根据key修改 value 记录
* 遍历所有记录。

### 3.使用Map
头文件 #include <map>。
map对象是模板类，需要关键字和存储对象两个模板参数： std:map<int, string> personnel; 这样就定义了一个用int作为索引，并拥有相关联的指向string的指针。

### 4. map的构造函数
实例化map对象 map<int, string> mapStudent;

### 5. 数据的插入
有以下三种方法

第一种：用insert函数插入pair数据
```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "One"));
	mapStudent.insert(pair<int, string>(2, "Two"));
	map<int, string>::iterator iter;
	for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	return 0;
}
```
第二种： 用insert 函数插入 value_type 数据
```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int, string> mapStudent;
	mapStudent.insert(map<int, string>::value_type (1, "One"));
	mapStudent.insert(map<int, string>::value_type (2, "Two"));
	map<int, string>::iterator iter;
	for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	return 0;
}
```

第三种： 用数组方式插入数据

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int, string> mapStudent;
	mapStudent[1] = "One";
	mapStudent[2] = "Two";
	map<int, string>::iterator iter;
	for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	return 0;
}
```

<b>用insert函数时，如果key存在，insert操作无法成功执行，但是用数组方式可以覆盖之前key对应的value。</b>

如何知道是否插入成功呢？ 可以用pair来获得是否插入成功:
pair<map<int, string>::iter, bool> Insert_Pair;
Insert_Pair = mapStudent.insert(map<int, string>::value_type(1, "One"));
我们通过pair的第二个变量来知道是否插入成功，他的第一个变量返回的是一个map的迭代器，如果插入成功的话Insert_Pair.second应该是true, 否则是 false。

···cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int, string> mapStudent;
	pair<map<int, string>::iterator, bool> Insert_Pair;
	Insert_Pair = mapStudent.insert(pair<int, string>(1, "One"));
	if(Insert_Pair.second == true)
		cout << "Insert Successfully" << endl;
	else
		cout << "Insert Failure" << endl;
	Insert_Pair = mapStudent.insert(pair<int, string>(1, "Two"));
	if(Insert_Pair.second == true)
		cout << "Insert Successfully" << endl;
	else
		cout << "Insert Failure" << endl;

	map<int, string>::iterator iter;
	for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	return 0;
}
```

### 6. map的大小
int mapSize = mapStudent.size();

### 7. map的遍历

第一种： 迭代器
```cpp
map<int, string>::iterator iter;
	for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
```
第二种： 反向迭代器
```cpp
map<int, string>::reverse_iterator iter;
	for(iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
		cout << iter->first << " " << iter->second << endl;
```
第三种： 用数组的形式
```cpp
for(int i = 1; i <= mapStudent.size(); i++)
  cout << mapStudent[i] << endl;
```

### 8. 查找

第一种： 用count函数，如果返回值为1则为存在， 返回值为0则不存在。

第二种： 用find 函数来定位数据出现位置，他返回一个迭代器，当数据存在时，它返回数据所在位置的迭代器，如果map中不存在要查找的数据，它返回的迭代器
等于end函数返回的迭代器。
查找map中是否包含某个关键字条目用find()方法，传入的参数是要查找的key，在这里需要提到的是begin()和end()两个成员，分别代表map对象中第一个条目
和最后一个条目，这两个数据的类型是iterator.

```def
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "One"));
	map<int, string>::iterator iter;
	iter = mapStudent.find(1);
	if(iter != mapStudent.end())
		cout << "Find " << iter -> first << " " << iter -> second << endl;
	else
		cout << "Do not find" << endl;
	for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << " " << iter->second << endl;
	return 0;
}
```

### 9. 删除
删除map中某个条目用erase()
iterator erase（iterator it);//通过一个条目对象删除

iterator erase（iterator first，iterator last）//删除一个范围

size_type erase(const Key&key);//通过关键字删除

clear()就相当于enumMap.erase(enumMap.begin(),enumMap.end());

```cpp
#include <map>  
  
#include <string>  
  
#include <iostream>  
  
using namespace std;  
  
int main()  
  
{  
  
       map<int, string> mapStudent;  
  
       mapStudent.insert(pair<int, string>(1, "student_one"));  
  
       mapStudent.insert(pair<int, string>(2, "student_two"));  
  
       mapStudent.insert(pair<int, string>(3, "student_three"));  
  
        //如果你要演示输出效果，请选择以下的一种，你看到的效果会比较好  
  
       //如果要删除1,用迭代器删除  
  
       map<int, string>::iterator iter;  
  
       iter = mapStudent.find(1);  
  
       mapStudent.erase(iter);  
  
       //如果要删除1，用关键字删除  
  
       int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0  
  
       //用迭代器，成片的删除  
  
       //一下代码把整个map清空  
  
       mapStudent.erase( mapStudent.begin(), mapStudent.end() );  
  
       //成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合  
  
       //自个加上遍历代码，打印输出吧  
  
}  
```
### 10. swap
map中的swap不是一个容器中的元素交换，而是两个容器所有元素的交换。


 
