#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	int sum = 0;
	for(int i = 0; i < s.length(); i++){
		if(isalpha(s[i]))
			sum += tolower(s[i]) - 'a' +1;
	}
	int cnt0 = 0, cnt1 = 0;
	while(sum != 0){
		if(sum % 2 == 0)
			cnt0++;
		else
			cnt1++;
		sum /= 2;
	}
	cout << cnt0 << " " << cnt1;
	return 0;
}
