#include <iostream>
using namespace std;
//合并左右子表
void Merge(int arr[], int left, int mid, int right)
{
	int *temp = new int[right - left];
	int t = 0;
	int i = left;
	int j = mid;
	while(i < mid && j < right){
		if(arr[i] <= arr[j]) temp[t++] = arr[i++];
		else temp[t++] = arr[j++];
	}
	while(i < mid) temp[t++] = arr[i++];
	while(j < right) temp[t++] = arr[j++];
	t = 0;
	for(int i = left; i < right; i++)
		arr[i] = temp[t++];
	delete[] temp;
}
//归并排序
void MSort(int arr[], int left, int right)
{
	if(left + 1 < right){
		int mid = (left + right) / 2;
		MSort(arr, left, mid);
		MSort(arr, mid, right);
		Merge(arr, left, mid, right);
	}
}

int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	MSort(a, 0 , len);
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
