#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
	int n, a, b, m;
	cin >> n;
	vector<int> v(100000, -1);  // 不能设0，因为00000 == 0
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v[a] = b;
		v[b] = a;
	}
	cin >> m;
	vector<int> g(m), isExist(100000);
	for(int i = 0; i < m; i++){
		scanf("%d", &g[i]);
		if(v[g[i]] != -1)
			isExist[v[g[i]]] = 1;
	}
	set<int> s;
	for(int i = 0; i < m; i++){
		if(!isExist[g[i]])
			s.insert(g[i]);
	}
	cout << s.size() << endl;
	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); it++){
		if(it != s.begin()) cout << " ";
//		cout << *it;
		printf("%05d", *it);  // 要设为5位输出，如00032会输出32
	}
	return 0;
}
