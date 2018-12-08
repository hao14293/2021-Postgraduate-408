#include <iostream>
using namespace std;
int main(){
	int m, n, e;
	float a[1001] = {0}, c;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d%f", &e, &c);
		a[e] += c;
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%f", &e, &c);
		a[e] += c;
	}
	int num = 0;
	for(int i = 0; i < 1001; i++){
		if(a[i] != 0)
			num++;
	}
	printf("%d", num);
	for(int i = 1000; i >= 0; i--){
		if(a[i] != 0.0)
			printf(" %d %.1f", i, a[i]);
	}
	return 0;
}
