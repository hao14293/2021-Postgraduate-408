#include <iostream>
using namespace std;

int main(){
	int k, sum = 0, maxSum = 0;
	cin >> k;
	for(int i = 0; i < k; i++){
		int temp;
		cin >> temp;
		sum += temp;
		if(sum < 0) sum = 0;
		if(sum > maxSum) maxSum = sum;
	}
	cout << maxSum;
	return 0;
}
