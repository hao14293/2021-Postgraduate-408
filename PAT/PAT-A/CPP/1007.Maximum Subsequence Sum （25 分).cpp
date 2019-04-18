#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	int start = 0, end = n - 1, sum = -1, temp = 0, tempindex = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		temp = temp + v[i];
		if(temp < 0){
			temp = 0;
			tempindex = i + 1; 
		}else if(temp > sum){
			sum = temp;
			start = tempindex;
			end = i;
		} 
	}
	if(sum < 0) sum = 0;
	printf("%d %d %d", sum, v[start], v[end]);
	return 0;
}
