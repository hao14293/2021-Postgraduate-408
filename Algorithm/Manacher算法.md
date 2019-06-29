# 一： 背景
给定一个字符串，求出其最长回文子串。例如：
 1. s="abcd", 最长回文长度为 1；
 2. s="ababa"，最长回文长度为5；
 3. s="abccb"，最长回文长度为4。


 以上问题的传统思路大概是，遍历每一个字符，以该字符为中心向两边查找。其时间复杂度为 <code>O(n<sup>2</sup>)</code>,效率很差。

1975年，一个叫 Manacher 的人发明了一个算法， 该算法可以把时间复杂度降到 <code>O(n)</code>。
# 二：算法过程分析
  由于回文分为偶回文和奇回文，而在处理奇偶问题上会比较繁琐，所以这里我们使用一个技巧，具体做法是：在字符串首尾及各字符间各插入一个字符（前提这个字符未出现在串里）。
  
  举个例子：<code>s="abbahopxpo"</code>,转换为 <code>s_new="$#a#b#b#a#h#o#p#x#p#o#"</code>（这里的字符  ￥只是为了防止越界，下面代码会有说明），如此，s里起初有一个偶回文 <code>abba</code>和一个奇回文 <code>opxpo</code>，被转换为 <code>#a#b#b#a#</code> 和 <code>#o#p#x#p#o#</code>,长度都转换为了奇数.
  
定义一个辅助数组 <code>int p[]</code>, 其中 <code>p[i]</code> 表示以 <code>i</code>为中心的最长回文的半径，例如：



![6.png](https://i.loli.net/2019/06/29/5d16c90730ce073372.png)


可以看出， <code> p[i] - 1 </code> 正好是源字符串最长回文串的长度。

接下来的重点就是求解 p 数组， 如下图
 
 ![1.png](https://i.loli.net/2019/06/29/5d16bda5a877799771.png)
 
 设置两个变量， mx 和 id。mx 代表以 id 为 中心的最长回文的右边界,也就是 <code>mx = id + p[id] </code>。
 
 假设我们现在求 <code>p[i]</code>，也就是以 <code>i</code>为中心的最长回文半径，如果<code>i < mx</code>,如上图，那么：
 ```md
 if(i < mx)
     p[i] = min(p[2 * id - i], mx - i)
 ```
 <code>2 * id - i</code> 为 i 关于 id 的对称点，即上图的 j 点， 而 <code>p[j]</code>表示以 j 为中心的最长回文半径，因此我们可以利用  <code>p[j]</code>来加快查找。
 
 # 三： 代码
 ```cpp
 #include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000];
char s_new[2000];
int p[2000];

int Init(){
	int len = strlen(s);
	s_new[0] = '$';
	s_new[1] = '#';
	int j = 2;
	
	for(int i = 0; i < len; i++){
		s_new[j++] = s[i];
		s_new[j++] = '#';
	}
	s_new[j] = '\0'; // 字符串最后要以 \0 结尾
	
	return j; 
} 

int Manacher(){
	int len = Init();
	int max_len = -1;
	
	int id;
	int mx = 0;
	
	for(int i = 1; i < len; i++){
		if(i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;
		
		while(s_new[i - p[i]] == s_new[i + p[i]]) // 不需边界判断，因为左有'$',右有'\0'
			p[i]++;
		
		if(mx < i + p[i]){
			id = i;
			mx = i + p[i];
		} 
		
		max_len = max(max_len, p[i] - 1);
	}
	
	return max_len;
}

int main(){
	while(printf("请输入字符串: \n")){
		scanf("%s", s);
		printf("最长回文长度为 %d\n\n", Manacher());
	}
	return 0;
}
```
# 四：算法复杂度分析
文章开头已经提及，Manacher算法为线性算法，即使最坏情况下其时间复杂度亦为<code>O(n)</code>，在进行证明之前，我们还需要更加深入地理解上述算法过程。

根据回文的性质，<code>p[i]</code>的值基于以下三种情况得出：
* (1): j的回文串有一部分在id的之外，如下图
![1.png](https://i.loli.net/2019/06/29/5d16c31db1cd281256.png)

上图中，黑线为 id 的回文， i 与 j 关于 id 对称，红线为 j 的回文。那么根据代码此时 <code> p[i] = mx - i</code>,即紫线。那么 <code>p[i]</code>还可以更大么？答案是不可能！见下图：

![2.png](https://i.loli.net/2019/06/29/5d16c31dc0f1a55903.png)

假设右侧新增部分是 <code>p[i]</code>可以增加的部分，那么根据回文的性质，a等于d， 也就是说 id 的回文不仅仅是黑线，而是黑线 + 两条紫线，矛盾，所以假设不成立，故 <code>p[i] = mx - i</code>,不可以再增加一分。

* （2）：j回文串全部在id的内部，如下图

![3.png](https://i.loli.net/2019/06/29/5d16c31de3b2a27940.png)

根据代码，此时 <code>p[i] = p[j]</code>, 那么 ,<code>p[i]</code>还可以更大么？答案亦是不可能！见下图：

![4.png](https://i.loli.net/2019/06/29/5d16c31dc990f40806.png)

假设右侧新增的红色部分是<code>p[i]</code>可以增加的部分，那么根据回文的性质，a等于b，也就是说j的回文应该再加上a和b，矛盾，所以假设不成立，故<code>p[i] = p[j]</code>，也不可以再增加一分。

* （3）：j回文串左端正好与 id 的回文串左端重合，见下图：

![5.png](https://i.loli.net/2019/06/29/5d16c31dd7d7181410.png)

根据代码，此时 <code>p[i] = p[j]</code>或<code>p[i] = mx - i</code>， 并且<code>p[i]</code>还可以继续增加，所以需要

```cpp
while(s_new[i - p[i]] == s_new[i + p[i]])
    p[i]++;
```
根据（1）（2）（3），很容易推出 Manacher 算法的最坏情况，即为字符串内全是相同字符的时候。在这里我们重点研究 Manacher（）中的 for 语句，推算发现 for 语句内平均访问每个字符 5 次，即时间复杂度为：<code>T<sub>worst</sub>(n)=O(n)</code>。

同理，我们也很容易知道最佳情况下的时间复杂度，即字符串内字符各不相同的时候。推算得平均访问每个字符 4 次，即时间复杂度为：<code>T<sub>best</sub>(n)=O(n)</code>。
综上，Manacher 算法的时间复杂度为 <code>O(n)</code>。

原文[https://subetter.com/algorithm/manacher-algorithm.html](https://subetter.com/algorithm/manacher-algorithm.html)
