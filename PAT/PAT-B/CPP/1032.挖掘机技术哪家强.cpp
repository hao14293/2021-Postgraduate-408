#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N, num, score, sum;
	cin >> N;
	vector<int> v(N + 1);
	for(int i = 0; i < N; i++){
		cin >> num >> score;
		v[num] += score;
	}
	int max = v[1], t = 1;
	for(int i = 2; i <= N; i++){
		if(max < v[i]){
			max = v[i];
			t = i;
		}
	}
	cout << t << " " << max;
	return 0;
}
