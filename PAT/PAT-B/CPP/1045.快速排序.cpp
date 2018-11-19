#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, temp, max = 0, tmp = 0;
	scanf("%d", &n);                  //使用cin，cout会慢很多，就这个题，用cin,cout 是114ms, 用scanf,printf是41ms.
	vector<int> a(n), b(n), v(n);
	for(int i = 0; i < n; i++){
		scanf("%d",&temp);
		b[i] = a[i] = temp;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		if(a[i] == b[i] && b[i] > max)
			v[tmp++] = b[i];
		if(b[i] > max) max = b[i];
	}
	printf("%d\n", tmp);
	for(int i = 0; i < tmp; i++){
		printf("%d", v[i]);
		if(i != tmp-1) printf(" ");
	}
	printf("\n");
	return 0;
}
