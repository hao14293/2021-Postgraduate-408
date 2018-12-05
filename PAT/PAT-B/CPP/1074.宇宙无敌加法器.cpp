#include <iostream>
using namespace std;
int main(){
	string s, s1, s2, result;
	cin >> s >> s1 >> s2;
	result = s;
	int carry = 0, flag = 0;
	string ss1(s.length() - s1.length(), '0');
	s1 = ss1 + s1;
	string ss2(s.length() - s2.length(), '0');
	s2 = ss2 + s2;
	for(int i = s.length() - 1; i >= 0; i--){
		int mod = s[i] == '0' ? 10 : (s[i] - '0');
		result[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
		carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
	}
	if(carry != 0) result = '1' + result;
	for(int i = 0; i < result.size(); i++){
		if(result[i] != '0' || flag == 1){
			flag = 1;
			cout << result[i];
		}
	}
	if(flag == 0) cout << 0;
	return 0;
}
