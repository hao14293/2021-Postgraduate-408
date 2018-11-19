#include <iostream>
using namespace std;
int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	int m = len - 1, flag = 1;
	while((m > 0) && (flag == 1)){
		flag = 0;
		for(int i = 1; i <= m; i++){
			if(a[i - 1] > a[i]){
				flag = 1;
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
		}
		m--;
	}
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
