#include <iostream>
#include <string>

using namespace std;

/* P 为模式串，下标从 0 开始 */
void GetNext(string P, int next[])
{
    int p_len = P.size();
    int i = 0;   // P 的下标
    int j = -1;
    next[0] = -1;

    while (i < p_len - 1)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

/* 在 S 中找到 P 第一次出现的位置 */
int KMP(string S, string P, int next[])
{
    GetNext(P, next);

    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = S.size();
    int p_len = P.size();

    while (i < s_len && j < p_len)
    {
        if (j == -1 || S[i] == P[j])  // P 的第一个字符不匹配或 S[i] == P[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];  // 当前字符匹配失败，进行跳转
    }

    if (j == p_len)  // 匹配成功
        return i - j;

    return -1;
}

int main()
{
    int next[100] = { 0 };

    cout << KMP("bbc abcdab abcdabcdabde", "abcdabd", next) << endl; // 15

    return 0;
}
