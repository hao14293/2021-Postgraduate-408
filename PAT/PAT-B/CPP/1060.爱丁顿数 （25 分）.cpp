#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n + 1);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin() + 1, v.end(), cmp); 
    int e = 0, i = 1;
    while(i <= n && v[i] > i){
        ++e;
        ++i;
    }
    printf("%d\n", e);
    return 0;
}
