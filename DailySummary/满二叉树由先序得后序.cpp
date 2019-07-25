void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l1, int h2){
	int half;
	if(h1 >= l1){
		post[h2] = pre[l1];
		half = (h1 - l1) / 2;
		PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
		PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 -1);
	}
}
