#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int sum = 0;
	string str[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	for(int i = 0; i < s.length(); i++)
		sum += (s[i] - '0');
	string sum_num = to_string(sum);
	for(int i = 0; i < sum_num.length(); i++){
		if(i != 0) cout << " ";
		cout << str[sum_num[i] - '0'];
	}
	return 0;
}
