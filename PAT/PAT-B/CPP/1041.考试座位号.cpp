#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, N, t_num, temp;
	string num, s_num;
	cin >> N;
	vector<string> v(N+1);
	for(int i = 1; i <= N; i++){
		cin >> num >> t_num >> s_num;
		v[t_num] = num + " " + s_num;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		cout << v[temp] << endl;
	}
	return 0;
}
