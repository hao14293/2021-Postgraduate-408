
BiTree PreInCreat(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2){
	//初始调用 l1 = l2 = 1, h1 = h2 = n;
	root = (BiTNode*)malloc(sizeof(BiTNode));
	root->data = A[l1];
	for(int i = l2; B[i] != root->data; i++);
	llen = i - l2;
	rlen = h2 - i;
	if(llen)
		root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	if(rlen)
		root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root; 
}
