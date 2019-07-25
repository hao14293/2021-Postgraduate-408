bool IsComplete(BiTree T){
	InitQueue(Q);
	if(!T) return 1;
	EnQueue(Q, T);
	while(!IsEmpty(Q)){
		DeQueue(Q, p);
		if(p){
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else{
			while(!IsEmpty(Q)){
				DeQueue(Q, p);
				if(p) return 0;
			}
		}
	}
	return 1;
}
