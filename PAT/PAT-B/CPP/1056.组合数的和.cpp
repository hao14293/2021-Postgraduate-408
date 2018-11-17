#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, temp, sum = 0;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> temp;
		v[i] = temp;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j) sum += v[i] * 10 + v[j];
		}
	}
	cout << sum;
	return 0;
}
