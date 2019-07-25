void DeleteXTree(BiTree bt){
	if(bt){
		DeleteXTree(bt->lchild);
		DeleteXTree(bt->rchild);
		free(bt);
	}
}

void Search(BiTree bt, ElemType x){
	BiTree Q[];
	if(bt){
		if(bt->data == x){
			DeleteXTree(bt);
			exit(0);
		}
		InitQueue(Q);
		EnQueue(Q, bt);
		while(!IsEmpty(Q)){
			DeQueue(Q, p);
			if(p->lchild){
				if(p->lchild->data == x){
					DeleteXTree(p->lchild);
					p->lchild = NULL;
				}
				else
					EnQueue(Q, p->lchild);
			}
			if(p->rchild){
				if(p->rchild->data == x){
					DeleteXTree(p->rchild);
					p->rchild = NULL;
				}
				else
					EnQueue(Q, p->rchild);
			}
		}
	}
}
