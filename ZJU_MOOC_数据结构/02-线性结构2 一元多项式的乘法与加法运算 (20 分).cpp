#include <iostream>

typedef int element;
typedef struct Node
{
	element coef;
	element exp;
	struct Node *Next;
}node;
using namespace std;

node *Read();
node *Add(node *L1, node *L2);
node *Mult(node *L1, node *L2);
void Print(node *L);
node *Insert(node *p, element c, element e);

int main()
{
	node *L1, *L2, *L3, *L4;
	L1 = Read();
	L2 = Read();
	L4 = Mult(L1, L2);
	L3 = Add(L1, L2);

	Print(L4);
	Print(L3);

	return 0;
}

node * Read()
{
	node *p;
	node *phead = new node;
	phead->Next = NULL;
	p = phead;
	int n, i = 0;
	cin >> n;

	while (i < n)
	{
		node *pNew = new node;
		cin >> pNew->coef >> pNew->exp;
		pNew->Next = NULL;
		p->Next = pNew;
		p = pNew;
		i++;
	}
	return phead;
}

node *Add(node *L1, node *L2)
{
	node *phead = new node;
	node *p1 = L1->Next;
	node *p2 = L2->Next;
	node *p3 = phead;
	phead->Next = NULL;

	while (p1 && p2)
	{
		node *t1, *t2;
		if (p1->exp == p2->exp)
		{
			t1 = p1;
			t2 = p2;
			t1->coef = p1->coef + p2->coef;		// list L1 as the new list L3's template;
			if (t1->coef != 0)
			{
				p3->Next = t1;
				p3 = t1;
				p1 = p1->Next;
				p2 = p2->Next;
				p3->Next = NULL;
				delete t2;
			}
			else
			{
				p1 = p1->Next;
				p2 = p2->Next;
				delete t1;
				delete t2;
			}
		}
		else if (p1->exp > p2->exp)
		{
			p3->Next = p1;
			p3 = p1;
			p1 = p1->Next;
			p3->Next = NULL;
		}
		else
		{
			p3->Next = p2;
			p3 = p2;
			p2 = p2->Next;
			p3->Next = NULL;
		}

	}

	if (p1)
		p3->Next = p1;
	if (p2)
		p3->Next = p2;

	L1->Next = NULL;
	L2->Next = NULL;

	return phead;
}

void Print(node *L)
{
	node *p = L->Next;
	if (!p)
		cout << "0 0" << endl;
	while (p)
	{
		if (p->Next != NULL)
			cout << p->coef << ' ' << p->exp << ' ';
		else
			cout << p->coef << ' ' << p->exp << endl;
		p = p->Next;
	}
	return;
}

node *Mult(node *L1, node *L2)		//key: insert list p3 by every node;
{
	element c, e;
	node *phead = new node;
	phead->Next = NULL;
	node *p1 = L1->Next;
	node *p2 = L2->Next;
	node *p3 = phead;

	if (!p1 || !p2)
		return phead;		//not 'NULL';

	while (p2)
	{
		node *pNew = new node;
		p3 = Insert(p3, p1->coef * p2->coef, p1->exp + p2->exp);
		p2 = p2->Next;
	}

	p1 = p1->Next;
	node *t;
	while (p1)
	{
		p2 = L2->Next;
		p3 = phead->Next;
		while (p2)
		{
			c = p1->coef * p2->coef;
			e = p1->exp + p2->exp;
			while (p3->Next && p3->Next->exp > e)
				p3 = p3->Next;

			if (p3->Next && p3->Next->exp == e)
			{
				if (p3->Next->coef + c != 0)
					p3->Next->coef += c;
				else
				{
					t = p3->Next;
					p3->Next = t->Next;
					delete t;
				}
			}
			else
			{
				p3 = Insert(p3, c, e);
			}

			p2 = p2->Next;
		}

		p1 = p1->Next;
	}

	return phead;
}

node *Insert(node *p, element c, element e)
{
	node *t = new node;
	t->coef = c;
	t->exp = e;
	t->Next = p->Next;
	p->Next = t;

	return t;
}
