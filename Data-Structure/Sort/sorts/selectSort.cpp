#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7};  //为了和教材一致，数组从第1位开始
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 1; i < len; i++){   
		int k = i;
		for(int j = i + 1; j < len; j++){
			if(a[j] < a[k]) k = j;
		}
		if(k != i){
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
