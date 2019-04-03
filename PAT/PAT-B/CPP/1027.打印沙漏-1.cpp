#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int N, n, t;
	cin >> N;
	char c;
	cin >> c;
	n = sqrt((N + 1) / 2);
	t = N - 2 * n * n + 1;
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < (2 * n - (2 * i - 1)) / 2; j++) cout << " ";
		for(int k = 0; k < 2 * i - 1; k++) cout << c;
		cout << endl;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < (2 * n - (2 * i - 1)) / 2; j++) cout << " ";
		for(int k = 0; k < 2 * i - 1; k++) cout << c;
		cout << endl;
	}
	if(N == 1) cout << "0"; // 坑
	if(t != 0) cout <<  t;
	return 0;
}
