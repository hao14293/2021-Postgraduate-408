#include <iostream>
using namespace std;
int main(){
	int m, n, a, b, r, temp;
	scanf("%d%d%d%d%d", &m, &n, &a, &b, &r);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &temp);
			if(temp >= a && temp <= b)
				printf("%03d",r);
			else
				printf("%03d", temp);
			if(j != n - 1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
