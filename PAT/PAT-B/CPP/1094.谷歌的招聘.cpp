#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(string s){
	int a = stoi(s);
	if(a < 2) return false;
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return false;
	}
	return true;
}

int main(){
	int l, k;
	scanf("%d%d", &l, &k);
	string s;
	cin >> s;
	int flag = 0;
	for(int i = 0; i < l - k + 1; i++){
		string temp = s.substr(i, k);
		if(isPrime(temp)){
			cout << temp;
			return 0;
		}
	}
	printf("404");
	return 0;
}
