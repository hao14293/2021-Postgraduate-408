#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPal(string s){
	for(int i = 0; i < s.length() / 2; i++){
		if(s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}
string add(string a, string b){
	string result;
	int num = 0, carry = 0;
	for(int i = 0; i < a.length(); i++){
		num = (a[i] - '0' + b[i] - '0') + carry;
		if(num >= 10){
			num -= 10;
			carry = 1;
		}else {
			carry = 0;
		}
		result += (num + '0');
	}
	if(carry == 1) result += '1';
	reverse(result.begin(), result.end());
	return result;
}
int main(){
	string a, b, c;
	cin >> a;
	int cnt = 1;
	while(!isPal(a) && cnt <= 10){
		cnt++;
		b = a;
		reverse(b.begin(), b.end());
		c = add(a, b);
		cout << a << " + " << b << " = " << c << endl;
		a = c;
	}
	if(cnt <= 10) cout << a << " is a palindromic number." << endl;
	else cout << "Not found in 10 iterations." << endl;
	return 0;
}
