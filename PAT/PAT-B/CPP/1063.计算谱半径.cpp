#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n, a, b;
	float max = 0.0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		float temp = sqrt(a * a + b * b);
		if(temp > max) max = temp;
	}
	printf("%.2f", max);
	return 0;
}
