#include <iostream>
using namespace std;
int main(){
	int n, d;
	float e, temp, may = 0, must = 0;
	cin >> n >> e >> d;
	for(int i = 0; i < n; i++){
		int k, sum = 0;
		cin >> k;
		for(int i = 0; i < k; i++){
			cin >> temp;
			if(temp < e) sum++;
		}
		if(k > d && sum * 2 > k) must++;
		else if(sum * 2 > k) may++;
	}
	may = may / n * 100;
	must = must / n * 100;
	printf("%.1f%% %.1f%%", may, must);
	return 0;
}
