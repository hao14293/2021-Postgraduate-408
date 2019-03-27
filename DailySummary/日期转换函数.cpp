#include <iostream>
#include <cmath>
using namespace std;

int converse(int n, int d){
	int arr[100], index = 0;
	while(n != 0){
		arr[index++] = n % d;
		n = n / d;
	}
	int result = 0;
	for(int i = index - 1; i >= 0; i--){
		result = result + arr[i] * pow(10, i);
	}
	return result;
}
int main(){
	int a, b;
	cin >> a >> b;
	cout << converse(a, b);
	return 0;
}
