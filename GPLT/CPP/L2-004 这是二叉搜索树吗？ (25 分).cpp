#include <iostream>
#include <vector>
using namespace std;

typedef struct TNode *BinTree;
struct TNode{
	int Data;
	BinTree Left;
	BinTree Right;
};

BinTree insert(BinTree BST, int Data){
	if(!BST){
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = Data;
		BST->Left = BST->Right = NULL;
	}
	else if(Data < BST->Data)
		BST->Left = insert(BST->Left, Data);
	else
		BST->Right = insert(BST->Right, Data);
	
	return BST;
}

void PreOrder(BinTree BST, vector<int>&a){
	if(!BST) return ;
	a.push_back(BST->Data);
	PreOrder(BST->Left, a);
	PreOrder(BST->Right, a);
}
void PreOrderMirror(BinTree BST, vector<int>&a){
	if(!BST) return ;
	a.push_back(BST->Data);
	PreOrderMirror(BST->Right, a);
	PreOrderMirror(BST->Left, a);
}
void PostOrder(BinTree BST, vector<int>&a){
	if(!BST) return ;
	PostOrder(BST->Left, a);
	PostOrder(BST->Right, a);
	a.push_back(BST->Data);
}
void PostOrderMirror(BinTree BST, vector<int>&a){
	if(!BST) return ;
	PostOrderMirror(BST->Right, a);
	PostOrderMirror(BST->Left, a);
	a.push_back(BST->Data);
}
vector<int> origin, Pre, PreM, PostM, Post;

int main(){
	int N, Data;
	BinTree BST = NULL;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> Data;
		origin.push_back(Data);
		BST = insert(BST, Data);
	}
	PreOrder(BST, Pre);
	PreOrderMirror(BST, PreM);
	PostOrder(BST, Post);
	PostOrderMirror(BST, PostM);
	if(origin == Pre){
		cout << "YES" << endl;
		for(int i = 0; i < Post.size(); i++){
			cout << Post[i];
			if(i < Post.size() - 1) cout << " ";
		}
	}else if(origin == PreM){
		cout << "YES" << endl;
		for(int i = 0; i < PostM.size(); i++){
			cout << PostM[i];
			if(i < PostM.size() - 1) cout << " ";
		}
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
