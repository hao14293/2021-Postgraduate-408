#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > graph;

voidbfs(int v){
	vector<int>::iterator it;
	visited[v] = true;
	cout << v << " ";
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(it = graph[v].begin(); it != graph[v].end(); it++){
			if(!visited[*it]){
				cout << *it << " ";
				q.push(*it);
				visited[*it] = true;
			}
		}
		cout << endl; 
	}
} 
