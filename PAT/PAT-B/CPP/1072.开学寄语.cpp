#include <iostream>
#include <string>
using namespace std;
bool isExist(string s, string v[], int len){
	for(int i = 0; i < len; i++){
		if(v[i] == s) return true;
	}
	return false;
}
int main(){
	int n, m, num = 0, total = 0;
	cin >> n >> m;
	string v[10];
	for(int i = 0; i < m; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++){
		string name, temp;
		int tmp;
		cin >> name >> tmp;
		bool flag = true;
		for(int j = 0; j < tmp; j++){
			cin >> temp;
			if(isExist(temp, v, m)){
				if(flag){
					cout << name << ":";
					flag = false;
					num++;
				}
				cout << " " << temp;;
				total++;
			}
		}
		if(!flag) printf("\n");
	}
	printf("%d %d", num, total);
	return 0;
}
