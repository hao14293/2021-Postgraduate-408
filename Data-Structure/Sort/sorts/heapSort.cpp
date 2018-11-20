#include <iostream>
using namespace std;

void adjust(int arr[], int len, int index)
{
	int left = 2 * index ;     //下标从0开始的话改为 2 * index + 1
	int right = 2 * index + 1; //下标从0开始的话改为 2 * index + 2
	int maxIdx = index;
	if(left < len && arr[left] > arr[maxIdx]) maxIdx = left;
	if(right < len && arr[right] > arr[maxIdx]) maxIdx = right;
	if(maxIdx != index)
	{
		int temp = arr[maxIdx];
		arr[maxIdx] = arr[index];
		arr[index] = temp;
		adjust(arr, len, maxIdx);
	}
}
void heapSort(int arr[], int size)
{
	for(int i = size / 2 ; i >= 1; i--)   //下标从0开始的话改为 size / 2 - 1; i >= 0;
		adjust(arr, size, i);
	for(int i = size - 1; i >= 1; i--)
	{
		int tmp = arr[1];   // 下标从0开始的话改为 arr[0]
		arr[1] = arr[i];
		arr[i] = tmp;
		adjust(arr, i, 1);
	}
}

int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; 
	int len = sizeof(a) / sizeof(a[0]);
	heapSort(a, len);
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
