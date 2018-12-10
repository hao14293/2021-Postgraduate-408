#include <iostream>
using namespace std;
int main(){
	int n, m, tmp, max = 0, v[1000] = {0};
	scanf("%d%d",&n, &m);  // n == 5, m == 3
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &tmp);
			v[j] += tmp;
			if(v[j] > max) max = v[j];
		}
	}
	printf("%d\n", max);
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == max){
			if(flag) printf(" ");
			flag = 1;
			printf("%d", i + 1);
		}
	}
	return 0;
}
