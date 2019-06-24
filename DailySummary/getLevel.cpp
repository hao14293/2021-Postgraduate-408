#include <iostream>
#include <vector>
using namespace std;

vector<int> InOrder, PreOrder, Level(10000, -1);
// 递归层次遍历 
void getLevel(int root, int start, int end, int index);

int main(){
	int n, cnt = 0;
	cin >> n;
	InOrder.resize(n);
	PreOrder.resize(n);
	//vector<int> InOrder(n), PreOrder(n), Level(n);
	for(int i = 0; i < n; i++)
		cin >> InOrder[i];
	for(int i = 0; i < n; i++)
		cin >> PreOrder[i];
	getLevel(0, 0, n-1, 0);
	for(int i = 0; i < Level.size(); i++){
		if(Level[i] != -1)
			cout << Level[i] << " ";
	}
	return 0; 
}

void getLevel(int root, int start, int end, int index){
	if(start > end) return ;
	int i = start;
	while(i < end && InOrder[i] != PreOrder[root]) i++;
	Level[index] = PreOrder[root];
	getLevel(root + 1, start, i - 1, 2 * index + 1);
	getLevel(root + 1 + i - start, i + 1, end, 2 * index + 2);
}
