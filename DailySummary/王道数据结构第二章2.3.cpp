#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
}DNode, *Dlinklist;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

// 2.3.1
void Del_x_1(LinkList &L, ElemType x){
	LNode *p;
	if(L == NULL) return;
	if(L->data == x){
		p = L;
		L =  L->next;
		free(p);
		Del_x_1(L, x);
	}
	else
		Del_x_1(L->next, x);
}

// 2.3.2
void Del_x_2(LinkList &L, ElemType x){
	LNode *p = L->next, *pre = L, *q;
	while(p != NULL){
		if(p->data == x){
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else{
			pre = p;
			p = p->next;
		}
	}
}

//2.3.2.2
void Del_x_3(LinkList &L, ElemType x){
	LNode *p = L->next, *r = L, *q;
	while(p != NULL){
		if(p->data != x){
			r->next = p;
			r = p;
			p = p->next;
		}
		else{
			q = p;
			p = p->next;
			free(q);
		}
	}
}

//2.3.3
void R_Print(LinkList L){
	if(L->next != NULL){
		R_Print(L->next);
	}
	printf(L->data);
}

// 2.3.4
LinkList Delete_Min(LinkList &L){
	LNode *pre = L, *p = L->next;
	LNode *minpre = pre, *minp = p;
	while(p != NULL){
		if(p->data < minp->data){
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next;
	free(minp);
	return L;
}

// 2.3.5
LinkList Reverse(LinkList L){
	LNode *p = L->next, *q;
	L->next = NULL;
	while(p != NULL){
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
	return L;
}

// 2.3.6
void Sort(LinkList &L){
	LNode *p = L->next, *pre;
	LNode *r = p->next;
	p->next = NULL;
	p = r;
	while(p != NULL){
		r = p->next;
		pre = L;
		while(pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}

// 2.3.7
void RangeDelete(LinkList &L, int min, int max){
	LNode *pr = L, *p = L->next;
	while(p != NULL){
		if(p->data > min && p->data < max){
			pr->next = p->next;
			free(p);
			p = pr->next;
		}
		else{
			pr = p;
			p = p->next;
		}
	}
}

// 2.3.8 
/* 
两个链表有公共结点，即两个链表从某一结点开始，他们的next都指向同一结点。
由于每个结点只有一个next域，因此从第一个公共结点开始，之后他们所有的节点都相同。 
*/
LinkList Search_Common(LinkList L1, LinkList L2){
	int len1 = L1.length(), len2 = L2.Length();
	LinkList longList, shortList;
	if(len1 > len2){
		longList = L1->next;
		shortList = L2->next;
		dist = len1 - len2;
	}
	else{
		longList = L2->next;
		shortList = L1->next;
		dist = len2 - len1;
	}
	while(dist--) longList = longList->next;
	while(longList != NULL){
		if(longList == shortList)
			return longList;
		else{
			longList = longList->next;
			shortList = shortList->next;
		}
	}
	return NULL;
}

// 2.3.9 
void Min_Delete(LinkList &head){
	while(head->next != NULL){
		pre = head;
		p = pre->next;
		while(p->next != NULL){
			if(p->next->data < pre->next->data){
				pre = p;
				p = p->next;
			}
			print(pre->next->data);
			u = pre->next;
			pre->next = u->next;
			free(u);
		}
		free(head);
	}
}
