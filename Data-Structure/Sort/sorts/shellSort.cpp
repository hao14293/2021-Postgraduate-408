#include <iostream>
using namespace std;
int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	int step = len / 2;  //初次增量为len/2
	while(step > 0){
		for(int i = step; i < len; i += step){
			while(i >= step && a[i - step] > a[i]){
				int temp = a[i - step];
				a[i - step] = a[i];
				a[i] = temp;
				i -= step;
			}
		}
		step = step / 2;
	}
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
