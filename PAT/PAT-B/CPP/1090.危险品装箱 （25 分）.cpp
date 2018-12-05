#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n, m, t1, t2;
	map<int, vector<int>> v;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&t1,&t2);
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	while(m--){
		int cnt, flag = 0, a[100000] = {0};
		scanf("%d",&cnt);
		vector<int> s(cnt);
		for(int i = 0; i < cnt; i++){
			scanf("%d",&s[i]);
			a[s[i]] = 1;
		}
		for(int i = 0; i < s.size(); i++)
			for(int j = 0; j < v[s[i]].size(); j++)
				if(a[v[s[i]][j]] == 1){
					flag = 1;
					break;
				}
		printf("%s\n", flag ? "No" : "Yes");
	}
	return 0;
}
