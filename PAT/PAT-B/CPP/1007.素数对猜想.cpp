#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}
 
int main(){
	int n, cnt = 0;
	cin >> n;
	for(int i = 2; i <= n; i++)
		if(isPrime(i - 2) && isPrime(i)) cnt++;
	cout << cnt;
	return 0;
}
