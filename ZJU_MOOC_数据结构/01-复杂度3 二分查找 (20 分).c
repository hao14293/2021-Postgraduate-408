Position BinarySearch( List L, ElementType X ){
    int p = 0;
    int s = 1;
    int e = L->Last;
    int num = e/2;
    while(num--){
        int mid = (s + e) / 2;
        if(L->Data[mid] == X){
            p = mid;
            break;
        }else if(L->Data[mid] > X){
            e = mid - 1;
        }else if(L->Data[mid] < X){
            s = mid + 1;
        }

    }
    if(p == 0)
        return NotFound;
    return p;
}
