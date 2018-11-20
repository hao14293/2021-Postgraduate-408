#include <iostream>
using namespace std;
int main(){
	int n, temp, num_a, num_b, max_num, max = 0;
	cin >> n;
	int team[1001] = {0};                       //用动态数组会很慢，静态数组虽然浪费空间但会很快
	for(int i = 0; i < n; i++){
		scanf("%d-%d%d",&num_a, &num_b, &temp);    //要灵活运用 scanf ,会比cin方便。
		team[num_a] += temp;
		if(team[num_a] > max){
			max_num = num_a;
			max = team[num_a];
		}
	}
	cout << max_num << " " << max;
	return 0;
}
