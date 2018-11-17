#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, m , temp, sum;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	for(int i = 0; i < m; i++){
		cin >> temp;
		a[i] = temp;
	}
	for(int i = 0; i < m; i++){
		cin >> temp;
		b[i] = temp;
	}
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = 0; j < m; j++){
			cin >> temp;
			if (temp == b[j]) sum += a[j];
		}
		cout << sum << endl;
	}
	return 0;
}
