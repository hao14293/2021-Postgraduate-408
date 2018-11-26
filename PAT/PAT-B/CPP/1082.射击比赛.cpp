#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct score{
	int id;
	int num;
};
bool cmp(score a, score b){
	return a.num < b.num;
}
int main(){
	int n, id, x, y;
	cin >> n;
	vector<score> v(n);
	for(int i = 0 ; i < n; i++){
		cin >> id >> x >> y;
		v[i].id = id;
		v[i].num = x * x + y * y;
	}
	sort(v.begin(), v.end(), cmp);
	printf("%04d %04d", v[0].id, v[n - 1].id);
	return 0;
}
