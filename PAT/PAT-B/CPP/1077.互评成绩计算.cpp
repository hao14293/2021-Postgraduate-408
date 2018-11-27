#include <iostream>
using namespace std;
int main(){
	int n, m, t, s;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> t;
		int sum = 0, max = -1, min = m + 1, num = 0;
		for(int j = 1; j < n; j++){
			cin >> s;
			if(s >= 0 && s <= m){
				sum += s;
				num++;
				if(s > max) max = s;
				if(s < min) min = s;
			}
		}
		sum = ((sum - max - min ) * 1.0 / (num - 2) + t) / 2 + 0.5;
		cout << sum << endl;
	}
	return 0;
}
