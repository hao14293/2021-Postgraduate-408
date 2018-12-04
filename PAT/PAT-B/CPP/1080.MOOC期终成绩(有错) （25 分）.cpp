#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
	string id;
	int gp, gpm = -1, gpf = -1, g = 0;
};

int isExist(string s, string a[], int len){
	for(int i = 0; i < len; i++){
		if(a[i] == s) return i;
	}
	return -1;
}
int cmp(node a, node b){
	return a.g != b.g ? a.g > b.g : a.id < b.id;
}
int main(){
	int p, m, n, tmp, cnt = 0;
	string a[10000], temp;
	cin >> p >> m >> n;
	vector<node> stu(p);
	for(int i = 0; i < p; i++){
		cin >> a[i] >> stu[i].gp;
		stu[i].id = a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> temp >> tmp;
		int j = isExist(temp, a, p);
		if(j != -1){
			stu[j].gpm = tmp;
		}
	}
	for(int i = 0; i < n; i++){
		cin >> temp >> tmp;
		int j = isExist(temp, a, p);
		if(j != -1){
			stu[j].gpf = tmp;
		}
	}
	for(int i = 0; i < p; i++){
		if(stu[i].gp >= 200){
			cnt++;
			if(stu[i].gpf > stu[i].gpm) stu[i].g = stu[i].gpf;
			else stu[i].g = stu[i].gpm * 0.4 + stu[i].gpf * 0.6 + 0.5;
		}
	}
	sort(stu.begin(), stu.end(), cmp);
	for(int i = 0; i < cnt; i++)
		if(stu[i].g >= 60){
			printf("%s %d %d %d %d\n",(stu[i].id).c_str(), stu[i].gp, stu[i].gpm, stu[i].gpf, stu[i].g);
		}
	return 0;
}
