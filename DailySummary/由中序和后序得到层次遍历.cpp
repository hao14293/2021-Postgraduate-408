#include <iostream>
#include <vector>
using namespace std;

vector<int> InOrder, PostOrder, Level(10000, -1);
// 递归层次遍历 
void getLevel(int root, int start, int end, int index);

int main(){
	int n, cnt = 0;
	cin >> n;
	InOrder.resize(n);
	PostOrder.resize(n);
	//Level.resize(n);
	//vector<int> InOrder(n), PreOrder(n), Level(n);
	for(int i = 0; i < n; i++)
		cin >> PostOrder[i];
	for(int i = 0; i < n; i++)
		cin >> InOrder[i];
	getLevel(n-1, 0, n-1, 0);
	for(int i = 0; i < Level.size(); i++){
		if(Level[i] != -1 && cnt != n - 1){
			cout << Level[i] << " ";
			cnt++;
		}else if(Level[i] != -1){ 
			cout << Level[i];
			break;
		}
	}
	return 0; 
}

void getLevel(int root, int start, int end, int index){
	if(start > end) return ;
	int i = start;
	while(i < end && InOrder[i] != PostOrder[root]) i++;
	Level[index] = PostOrder[root];
	getLevel(root - 1 - end + i, start, i - 1, 2 * index + 1);
	getLevel(root - 1, i + 1, end, 2 * index + 2);
}
