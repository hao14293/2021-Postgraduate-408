#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 2010;
const int INF = 100000000;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, numPerson = 0;
bool vis[maxn] = {false};

void DFS(int nowVisit, int &head, int &numMember, int &totalValue){
	numMember++;
	vis[nowVisit] = true;
	if(weight[nowVisit] > weight[head])
		head = nowVisit;
	
	for(int i = 0; i < numPerson; i++){
		if(G[nowVisit][i] > 0){
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(vis[i] == false)
				DFS(i, head, numMember, totalValue);
		}
	}
} 

void DFSTrave(){
	for(int i = 0; i < numPerson; i++){
		if(vis[i] == false){
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if(numMember > 2 && totalValue > k)
				Gang[intToString[head]] = numMember;
		}
	}
}

int change(string str){
	if(stringToInt.find(str) != stringToInt.end()){
		return stringToInt[str];
	}else{
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}

int main(){
	int w;
	string str1, str2;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for(it = Gang.begin(); it != Gang.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
