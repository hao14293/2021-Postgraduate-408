#include <iostream>
using namespace std;

int main(){
	int n, d;
	scanf("%d %d", &n, &d);
	int arr[40], index = 0;
	while(n != 0){
		arr[index++] = n % d;
		n = n / d;
	}
	int flag = 0;
	for(int i = 0; i < index / 2; i++){
		if(arr[i] != arr[index - i - 1]){
			printf("No\n");
			flag = 1;
			break;
		}
	}
	if(!flag) printf("Yes\n");
	for(int i = index - 1; i >= 0; i--){
		printf("%d", arr[i]);
		if(i != 0) printf(" ");
	}
	if(index == 0)
		printf("0");
	return 0;
}
