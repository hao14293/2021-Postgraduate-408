#include <iostream>
#include <string>
using namespace std;

int main(){
	int a[10] = {0};
	string s;
	cin >> s;
	int flag = 0, len = s.length();
	for(int i = len - 1; i >= 0; i--){
		int temp = s[i] - '0';
		a[temp]++;
		temp = temp * 2 + flag;
		flag = 0;
		if(temp >= 10){
			temp = temp - 10;
			flag = 1;
		}
		s[i] = temp + '0';
		a[temp]--;
	}
	int flag1 = 0;
	for(int i = 0; i < 10; i++){
		if(a[i] != 0) flag1 = 1;
	}
	printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
	if(flag == 1) printf("1");
	cout << s;
	return 0;
}
