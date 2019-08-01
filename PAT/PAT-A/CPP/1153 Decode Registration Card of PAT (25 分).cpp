#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 
struct stu{
	string id;
	int sco;
};
struct site{
	string siteId;
	int cnt;
};
bool cmp1(stu a, stu b) {
    return a.sco == b.sco ? a.id < b.id : a.sco > b.sco;
}
bool cmp2(site a, site b) {
    return a.cnt == b.cnt ? a.siteId < b.siteId : a.cnt > b.cnt;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<stu> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i].id >> v[i].sco;
	for(int i = 1; i <= k; i++){
		int num;
		cin >> num;
		if(num == 1){
			string level;
			cin >> level;
			printf("Case %d: %d %s\n", i, num, level.c_str());
			vector<stu> ans;
			for(int j = 0; j < n; j++){
				if(v[j].id[0] == level[0])
					ans.push_back(v[j]);
			}
			sort(ans.begin(), ans.end(), cmp1);
			for(int j = 0; j < ans.size(); j++)
				printf("%s %d\n", ans[j].id.c_str(), ans[j].sco);
			if(ans.size() == 0) printf("NA\n"); 
		}else if(num == 2){
			int cnt = 0, sum = 0;
			int siteId;
			cin >> siteId;
			printf("Case %d: %d %d\n", i, num, siteId);
			vector<stu> ans;
			for(int j = 0; j < n; j++){
				if(v[j].id.substr(1, 3) == to_string(siteId)){
					cnt++;
					sum += v[j].sco;
				}
			}
			if(cnt != 0) printf("%d %d\n", cnt, sum);
			else printf("NA\n");
		}else if(num == 3){
			string data;
			cin >> data;
			printf("Case %d: %d %s\n", i, num, data.c_str());
			vector<site> ans;
			unordered_map<string, int> m;
			for(int j = 0; j < n; j++){
				if(v[j].id.substr(4, 6) == data){
					string tt = v[j].id.substr(1, 3);
					m[tt]++;
				}
			}
			for(auto it : m)
				ans.push_back({it.first, it.second});
			sort(ans.begin(), ans.end(), cmp2);
			for(int j = 0; j < ans.size(); j++)
				printf("%s %d\n", ans[j].siteId.c_str(), ans[j].cnt);
			if(ans.size() == 0) printf("NA\n");
		}
	}
	return 0;
}
