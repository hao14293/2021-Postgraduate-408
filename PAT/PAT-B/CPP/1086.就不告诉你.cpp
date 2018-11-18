#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	string result = to_string(a * b);
	reverse(result.begin(), result.end());
	cout << stoi(result);  //最后输出int , string 不行
	return 0;
}
