#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}

	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}

	return 0;
}

BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if (X < BST->Data)
		BST->Left = Insert(BST->Left, X);
	else if (X > BST->Data)
		BST->Right = Insert(BST->Right, X);

	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	BinTree Temp;
	if (!BST)
		printf("Not Found\n");
	else if (X < BST->Data)
		BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)
		BST->Right = Delete(BST->Right, X);
	else
	{
		if (BST->Left && BST->Right)	//有两个子结点，用右子节点最大代替。
		{
			Temp = FindMin(BST->Right);
			BST->Data = Temp->Data;
			BST->Right = Delete(BST->Right, Temp->Data);
		}
		else	//有一个子结点或没有。
		{
			Temp = BST;
			if (BST->Left) 	//只有左子结点；
				BST = BST->Left;
			else	//只有右子结点；
				BST = BST->Right;
			free(Temp);
		}
	}
	
	return BST;
}

Position Find(BinTree BST, ElementType X)
{
	if (!BST)
		return NULL;

	if (X < BST->Data)
		return(Find(BST->Left, X));
	else if (X > BST->Data)
		return(Find(BST->Right, X));
	else
		return BST;
}

Position FindMin(BinTree BST)
{
	if (!BST)
		return NULL;
	if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
	if (!BST)
		return NULL;
	if (!BST->Right)
		return BST;
	else
		return FindMax(BST->Right);
}
