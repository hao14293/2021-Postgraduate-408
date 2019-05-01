#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int first, n, k, temp;
	cin >> first >> n >> k;
	int data[100000], next[100000], list[100000];
	for(int i = 0; i < n; i++){
		cin >> temp;
		cin >> data[temp] >> next[temp];
	}
	int sum = 0;
	while(first != -1){
		list[sum++] = first;
		first = next[first];
	}
	for(int i = 0; i < (sum - sum % k); i += k)
		reverse(begin(list) + i, begin(list) + i + k);
	for(int i = 0; i < sum - 1; i++)
		printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
	printf("%05d %d -1", list[sum - 1], data[list[sum - 1]]);
	return 0; 
}
