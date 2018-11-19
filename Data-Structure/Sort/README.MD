## 排序
* 插入排序
 >> [直接插入排序](#straight_insertSort)<br>
 >>[折半插入排序](#binary_insertSort)<br>
 >> [希尔排序](#shellSort)<br>
* 交换排序
 > [冒泡排序](#bubbleSort)<br>
 > [快速排序](#quickSort)<br>
* 选择排序
 > [简单选择排序](#simple_selectSort)<br>
 > [堆排序](#heapSort)<br>

### <span id="insertSort">插入排序</span>
<b>基本思想：</b>每一趟将一个待排序的记录，按其关键字的大小插入到已排好序的一组记录的适当位置上，直到所有待排序记录全部插入为止。

#### <span id="straight_insertSort">直接插入排序(straight Insertion sort)<span>

核心：通过构建有序序列，对于未排序序列，在已排序序列中从后向前扫描(对于单向链表则只能从前往后遍历)，找到相应位置并插入。

* 从第一个元素开始，该元素可认为已排序
* 取下一个元素，对已排序数组从后往前扫描
* 若从排序数组中取出的元素大于新元素，则移至下一位置
* 重复步骤3，直至找到已排序元素小于或等于新元素的位置
* 插入新元素至该位置
* 重复2~5

![insertion_sort.gif](https://i.loli.net/2018/11/18/5bf1093035260.gif)

代码实现
```cpp
#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //数组从第二位开始,第一位[0]为暂存单元
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		if(a[i] < a[i - 1]){
			a[0] = a[i];
			a[i] = a[i - 1];
			int j = i - 2;
			while(a[0] < a[j]){
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1 ] = a[0];
		}
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
```
算法分析
* 空间复杂度：需要一个记录的辅助空间[0],空间复杂度为 O(1).
* 时间复杂度：一共操作了 n-1 趟，每趟都分为比较和移动两部分。最好情况，只比较不移动，O(n);最坏情况，比较 n<sup>2</sup>/2 次，移动 n<sup>2</sup>/2 次， 时间复杂度为O(n<sup>2</sup>).

算法特点
* 稳定排序。
* 也适合于链式存储，只需修改相应的指针，无需移动。
* 适合于初始记录基本有序(正序)的情况，当初始记录无序，n较大时，此算法时间复杂度较高，不宜使用。
***
#### <span id="binary_insertSort">折半插入排序(Binary Insertion Sort)</span>
直接插入排序每一趟都需要在排好序的部分中从最后一位开始比较。折半插入排序减少了比较的次数，但移动次数没有改变。

代码实现
```cpp
#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7}; //数组从第二位开始, 第一位[0]为暂存单元
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 2; i < len; i++){
		a[0] = a[i];
		int low = 1, high = i - 1;
		while(low <= high){
			int m = (low + high) / 2;
			if(a[0] < a[m]) high = m - 1;
			else low = m + 1;
		}
		for(int j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		a[high + 1] = a[0];
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
```
算法分析
* 时间复杂度：移动次数没有变，所以时间复杂度还是 O(n<sup>2</sup>).
* 空间复杂度：O(1).

算法特点
* 稳定排序。
* 只能用于顺序结构，不能用于链式结构。
* 适合初始记录无序、n较大时的情况。
***
#### <span id="shellSort">希尔排序(Shell's Sort)</span>
直接插入排序，当<b>待排序的记录个数较少</b>且<b>待排序序列的关键字基本有序</b>时，效率较高。希尔排序针对以上两个方面进行了改进。
希尔排序实现上是将待排序序列分成几组分别进行插入排序，最后再合成一组。

基本思想: 先取一个小于n的整数d1作为第一个增量，把文件的全部记录分组。所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直接插入排序；然后，取第二个增量d2<d1重复上述的分组和排序，直至所取的增量 =1，即所有记录放在同一组中进行直接插入排序为止。
一般的初次取序列的一半为增量，以后每次减半，直到增量为1。

代码实现
```cpp
#include <iostream>
using namespace std;
int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	int step = len / 2;  //初次增量为len/2
	while(step > 0){
		for(int i = step; i < len; i += step){
			while(i >= step && a[i - step] > a[i]){
				int temp = a[i - step];
				a[i - step] = a[i];
				a[i] = temp;
				i -= step;
			}
		}
		step = step / 2;
	}
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
```
算法分析：
* 时间复杂度：最坏情况 O(n<sup>2</sup>)
* 空间复杂度：只需要一个辅助空间，O(1).

算法特点:
* 不稳定排序。
* 只能用于顺序结构。
* 记录总的比较次数和移动次数都比直接插入排序要少，n越大时，效果越明显。适合初始记录无序、较大时的情况。

***
### 交换排序
交换排序的基本思想是：两两比较待排序记录的关键字，一旦发现两个记录不满足次序要求时则进行交换，直到整个序列全部满足要求为止。
#### <span id="bubbleSort">冒泡排序(Bubble Sort)</span>
核心：冒泡，持续比较相邻元素，大的挪到后面，因此大的会逐步往后挪，故称之为冒泡。<br>
每一次循环将未排序数组中最大的移到最后，所以下一次循环可以只比较到前一位

![BubbleSort](https://i.loli.net/2018/11/17/5beff17418dbc.gif)

算法实现
```cpp
#include <iostream>
using namespace std;
int main(){
	int a[] = {6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	int m = len - 1, flag = 1;
	while((m > 0) && (flag == 1)){
		flag = 0;
		for(int i = 1; i <= m; i++){
			if(a[i - 1] > a[i]){
				flag = 1;
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
		}
		m--;
	}
	for(int i = 0; i < len; i++)
		cout << a[i];
	return 0;
}
```
算法分析
* 时间复杂度： 最好情况下只进行 n-1 次比较； 最坏情况下，进行 n(n-1)/2 次比较，移动 3n(n-1)/2次。时间复杂度为 O(n<sup>2</sup>).
* 空间复杂度： 只需要一个暂存空间， O(1).

算法特点
* 稳定排序
* 可用于链式存储
* 移动次数较多，算法平均时间性能比直接插入排序差。当初始记录无序，n较大时，不宜采用.
***
#### <span id="quickSort">快速排序(Quick Sort)</span>
可以参考[这篇文章](./quickSort.md)。另外，我总结的是按照严蔚敏教材的内容，所以与那篇文章有所不同，不过思想是一样的。

快速排序是对冒泡排序的一种改进。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

【算法步骤】

设要排序的数组是A[0]……A[N-1]，首先任意选取一个数据（通常选用数组的第一个数）作为枢纽(或支点)，然后将所有比它小的数都放到它前面，所有比它大的数都放到它后面，结果将待排序记录分成两个子表，枢纽处于最终位置。然后分别对左右子表重复上述过程，直到每一个子表只有一个记录时，排序完成。值得注意的是，快速排序不是一种稳定的排序算法，也就是说，多个相同的值的相对位置也许会在算法结束时产生变动。<br>

【具体步骤】<br>

* 选择待排序表中的第一个记录作为枢纽，将枢纽记录暂存在r[0]的位置上。附设两个指针low和high，初始时分别指向表的下界和上届(第一趟时，low=1;high=length-1;)。
* 从表的最右侧位置依次向左搜索，找到第一个小于关键字pivotkey的记录，将其移到low处。(当low<high时，若 r[high]>=pivotkey , high--; 若 r[high]<pivotkey, r[low]=r[high];)
* 然后再从左依次向右搜索第一个大于privotkey的记录，将其移到此时的high处。
* 重复2和3，直到low==high位置，此时low==high这个位置就是pivotkey(即此时的r[0])的最终位置，原表被分为两个子表。
* 分别对左右表执行以上操作。(递归).

代码实现
```cpp
#include <iostream>
using namespace std;
void quickSort(int list[], int low, int high)
{
	if(low < high){
		list[0] = list[low];
		int key = list[low];
		int left = low, right = high;
		while(low < high){
			while(low < high && list[high] >= key) high--;
			list[low] = list[high];
			while(low < high && list[low] <= key) low++;
			list[high] = list[low];
		}
		list[low] = list[0];
		quickSort(list,left,low-1);
		quickSort(list, low+1, right);
	}
}
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7};
	int len = sizeof(a) / sizeof(a[0]);
	quickSort(a, 1, len - 1);
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
```
【算法分析】<br>
* 空间复杂度：快速排序是递归的，执行时需要一个栈来存放相应数据。最大递归次数与递归树的深度一致，所以最好情况下的空间复杂度为 O(log<sub>2</sub>n)，最坏情况下为 O(n).
* 时间复杂度：最好情况：每一趟排序后都能将序列均匀分割成两个长度大致相等的子表，类似折半查。此时时间复杂度为 O(nlog<sub>2</sub>n)。最坏情况为待排序列基本有序，每次只能划分比上一次少一个的子序列。平均时间复杂度为 O(nlog<sub>2</sub>n)。

【算法特点】<br>
* 不稳定排序。
* 需要两个位置指针，很难用于链式结构。
* 当n较大时，在平均情况下快速排序时内部排序方法中速度最快的一种，所以适合初始记录无序、n较大时的情况。
***
### 选择排序
选择排序的基本思想是：每一趟从待排序的记录中选出关键字最小的记录，按顺序放在已排序的记录序列的最后，直到排完为止。
#### <span id="simple_selectSort">简单选择排序(Simple Selection Sort)</span>
核心： 每一趟在未排序序列中选择最小的记录放到已排序序列的最后。

【算法步骤】
* 第一趟从r[1]开始，从待排序序列[r[1]...r[n]]中找到最小的记录r[k]，交换r[1]和r[k]。
* 第二趟从r[2]开始，通过n-2次查找，从 n-1 个记录中找到最小的r[k]，交换r[2]和r[k]。
* 依次类推，经过 n-1 趟， 排序完成。

![selection_sort.gif](https://i.loli.net/2018/11/19/5bf24d65cc103.gif)

代码实现
```cpp
#include <iostream>
using namespace std;
int main(){
	int a[] = {-1, 6, 5, 2, 8, 4, 1, 3, 7};  //为了和教材一致，数组从第1位开始
	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 1; i < len; i++){   
		int k = i;
		for(int j = i + 1; j < len; j++){
			if(a[j] < a[k]) k = j;
		}
		if(k != i){
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
	for(int i = 1; i < len; i++)
		cout << a[i];
	return 0;
}
```
【算法分析】
* 空间复杂度: O(1).
* 时间复杂度: 简单排序所需移动次数较少。最好情况（正序），不移动，最坏情况（逆序），移动 3(n-1) 次。 无论初始排列如何，所需进行比较的次数相同，均为 n<sup>2</sup>/2次。

【算法特点】
* 稳定性：就选择排序方法本身来讲，它是一种稳定的排序方法。但某些情况下，如 a[]=[2,2,1],第一趟，a[0]与a[2]交换，两个2 a[0] 与a[1]的相对位置发生改变，这是因为采用“交换记录”的策略所造成的，改变这个策略，可以写出不产生这种不稳定现象的选择排序算法。
* 可用于链式存储结构。
* 移动记录次数较少，当每一记录占用的空间较多时，此方法比直接插入排序快。
***
#### <span id="heapSort">堆排序(Heap Sort)</span>
