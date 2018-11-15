#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, m, temp;
	cin >> n;
	vector<int> b(101);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);  // cin比scanf慢
		b[temp]++;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		scanf("%d", &temp);
		if(i != 0) printf(" ");
		printf("%d",b[temp]);
	}
	return 0;
}
