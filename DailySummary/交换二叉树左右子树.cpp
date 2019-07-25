void swap(BiTree b){
	if(b){
		swap(b->lchild);
		swap(b->rchild);
		temp = b->lchild;
		b->lchild = b->rchild;
		b->rchild = temp;
	}
}
