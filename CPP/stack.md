```md
#include <stack>

stack<int> v;

empty() 堆栈为空则返回真

pop() 移除栈顶元素

push() 在栈顶增加元素

size() 返回栈中元素数目

top() 返回栈顶元素
```
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	stack<string> v;
	string s;
	while(cin >> s) v.push(s);
	cout << v.top();
	v.pop();
	while(!v.empty()){
		cout << " " << v.top();
		v.pop();
	}
	return 0;
}
```
