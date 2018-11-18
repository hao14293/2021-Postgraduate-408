#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //数组从第二位开始, 第一位[0]为暂存单元
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		a[0] = a[i];
		int low = 1, high = i - 1;
		while(low <= high){
			int m = (low + high) / 2;
			if(a[0] < a[m]) high = m - 1;
			else low = m + 1;
		}
		for(int j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		a[high + 1] = a[0];
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
