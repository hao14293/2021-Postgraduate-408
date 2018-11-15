#include <iostream>
using namespace std;
int main(){
	int G, S, K, G1, S1, K1, sum;
	scanf("%d.%d.%d %d.%d.%d.",&G,&S,&K,&G1,&S1,&K1);
	sum = (K1 + S1 * 29 + G1 * 17 * 29) - (K + S * 29 + G * 17 * 29);
	if (sum < 0){
		cout << "-";
		sum = -1 * sum;
	}
	G = sum / 17 / 29;
	sum -= G * 17 * 29;
	S = sum / 29;
	sum -= S * 29;
	K = sum;
	cout << G << '.' << S << '.' << K << endl;
	return 0;
}
