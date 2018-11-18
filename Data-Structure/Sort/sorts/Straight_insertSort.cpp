#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //数组从第二位开始,第一位[0]为暂存单元
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		if(a[i] < a[i - 1]){
			a[0] = a[i];
			a[i] = a[i - 1];
			int j = i - 2;
			while(a[0] < a[j]){
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1 ] = a[0];
		}
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
