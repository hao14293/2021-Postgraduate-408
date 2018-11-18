#include <iostream>
using namespace std;
int main(){
	int T, k, n1, b, t, n2;
	cin >> T >> k;
	int sum = T;
	for(int i = 0; i < k; i++){
		cin >> n1 >> b >> t >> n2;
		if(sum == 0){
			cout << "Game Over.";
			return 0;
		}
		else if(t <= sum){
			if((b == 0 && n1 > n2) || (b == 1 && n1 < n2)){
				sum += t;
				printf("Win %d!  Total = %d.\n", t, sum);
			}
			else if((b == 0 && n1 < n2) || (b == 1 && n1 > n2)){
				sum -= t;
				printf("Lose %d.  Total = %d.\n", t, sum);
			}
		}
		else{
			printf("Not enough tokens.  Total = %d.\n", sum);
		}
	}
	return 0;
}
