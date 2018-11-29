#include <iostream>
#include <string>
using namespace std;
float toNum(string s){
	int cnt=0, len = s.length();
	string t;
	for(int i = 0; i < len; i++){
		if(s[i] != '.'){
			t += s[i];
		}
		else{
			cnt = len - 1 - i;
		}
	}
	float result = stoi(t) * 1.0;
	for(int i = 0; i < cnt; i++)
		result *= 0.1;
	return result;
}
bool leg(string s){
	int dot = 0, len = s.length();
	if(len == 0) return false;
	for(int i = 0; i < len; i++){
		if(s[0] == '-') continue;
		int tmp = (int)s[i];
		if((tmp < 48 || tmp > 57) && tmp != 46){
			return false;
		}else if(tmp == 46){
			if(len - i - 1 > 2) return false;
			dot++;
			if(dot >= 2) return false;
		}
	}
	if(toNum(s) < -1000 || toNum(s) > 1000) return false;
	return true;
}
int main(){
	int n, cnt = 0;
	float sum = 0.00;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(leg(s)){
			cnt++;
			sum += toNum(s);
		}else{
			cout << "ERROR: " << s <<" is not a legal number" << endl;
		}
	}
	sum = sum / cnt * 1.0;
	if(cnt == 0){
		printf("The average of 0 numbers is Undefined\n");
	}else{
		printf("The average of %d numbers is %.2f\n", cnt, sum);
	}
	return 0;
}
