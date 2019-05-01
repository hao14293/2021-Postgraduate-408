List Merge( List L1, List L2 ){
	List L, p1, p2, tail;
	L = (List)malloc(sizeof(PtrToNode));
	p1 = L1 -> Next;
	p2 = L2 -> Next;
	tail = L;
	while(p1 && p2){
		if(p1 -> Data < p2 -> Data){
			tail -> Next = p1;
			tail = p1;
			p1 = p1 -> Next;
			L1 -> Next = NULL;
			L2 -> Next = NULL;
		}else{
			tail -> Next = p2;
			tail = p2;
			p2 = p2 -> Next;
			L1 -> Next = NULL;
			L2 -> Next = NULL;
		}
	}
	if(p1){
		tail -> Next = p1;
	}else{
		tail -> Next = p2;
	}
	return L;
} 
