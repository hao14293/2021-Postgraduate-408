#include <iostream>
#include <set>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	set<int> v;
	for(int i = 1; i <= n; i++)
		v.insert(i / 2 + i / 3 + i / 5);
	printf("%d", v.size());
	return 0;
}
