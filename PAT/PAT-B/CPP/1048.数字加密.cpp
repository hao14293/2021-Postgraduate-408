#include <iostream>
using namespace std;
string reverse(string s){
	int len = s.length();
	for(int i = 0; i <= len / 2 - 1; i++)
		swap(s[i], s[len - 1 - i]);
	return s;
}
int main(){
	string a, b, c;
	cin >> a >> b;
	a = reverse(a);
	b = reverse(b);
	if(a.length() > b.length())
		b.append(a.length() - b.length(), '0');
	else
		a.append(b.length() - a.length(), '0');
	char str[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
	for(int i = 0; i < a.length(); i++){
		if(i % 2 == 0)
			c += str[(a[i] - '0' + b[i] - '0') % 13];
		else{
			int temp = b[i] - a[i];
			if(temp < 0) temp = temp + 10;
			c += str[temp];
		}
	}
	for(int i = c.length() - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}
