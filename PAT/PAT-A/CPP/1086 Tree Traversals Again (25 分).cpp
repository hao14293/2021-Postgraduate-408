#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int find_pos(vector<int> &v, int data){
	unsigned int i;
	for(i = 0; i < v.size(); i++){
		if(v[i] == data) break;
	}
	return i;
}

void post_traverse(vector<int> &pre, vector<int> &ino, int left, int right, int head){
	int pa_pos = find_pos(ino, pre[head]);
	int left_size = pa_pos - left + 1;
	if(head < (int)pre.size()){
		if(pa_pos > left)
			post_traverse(pre, ino, left, pa_pos - 1, head + 1);
		if(pa_pos < right)
			post_traverse(pre, ino, pa_pos + 1, right, head + left_size);
		if(head == 0)
			cout << pre[head] << endl;
		else
			cout << pre[head] << " ";
	}
} 

int main(){
	int n, i, node;
	string str;
	stack<int> sta;
	vector<int> pre, ino;
	cin >> n;
	for(i = 0; i < 2 * n; i++){
		cin >> str;
		if(str == "Push"){
			cin >> node;
			pre.push_back(node);
			sta.push(node);
		}
		else{
			ino.push_back(sta.top());
			sta.pop();
		}
	}
	
	post_traverse(pre, ino, 0, n - 1, 0);
	
	return 0;
}
