#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.length(); i++){
		sum += s[i] - '0';
	}
	string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string t = to_string(sum);
	for(int i = 0; i < t.length(); i++){
		if(i != 0) cout << " ";
		cout << str[t[i] - '0'];
	}
	return 0;
}
