#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L){
	LNode *s;
	ElemType x;
	L->next = NULL;
	scanf("%d", &x);
	while(x != 99999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

LinkList List_TailInsert(LinkList &L){
	ElemType x;
	L = (LinkList*)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while(x != 99999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

LNode *GetElem(LinkList L, int i){
	int j = 1;
	LNode *p = L->next;
	if(i == 0) return L;
	if(i < 1) return NULL;
	while(p && j < i){
		p = p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList L, ElemType e){
	LNode *p = L->next;
	while(p != NULL && p->data != e)
		p = p->next;
	return p;
}

LNode *PostInsert(LinkList &L, ElemType i){
	LNode *p = GetElem(L, i - 1);
	LNode *s;
	s->next = p->next;
	p->next = s;
	
	return L;
}

LNode *PreInsert(LinkList &L, ElemType i){
	LNode *p = GetElem(L, i -1);
	LNode *s;
	s->next = p->next;
	p->next = s;
	ElemType temp = p->data;
	p->data = s->data;
	s->data = temp;
	
	return L;
}

LNode *Delete(LinkList &L, ElemType i){
	LNode *p = GetElem(L, i - 1);
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	
	/*
	q=p->next;
	p->data=p->next->data;
	p->next=q->next;
	free(q);
	    */
}
