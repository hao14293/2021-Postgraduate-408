#include <iostream>
using namespace std;
int main(){
	int n, jia_a, jia_b, yi_a, yi_b, jia_count = 0, yi_count = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> jia_a >> jia_b >> yi_a >> yi_b;
		if(jia_b == jia_a + yi_a && jia_b != yi_b) yi_count++;
		if(yi_b == jia_a + yi_a && yi_b != jia_b) jia_count++;
	}
	cout << jia_count << " " << yi_count;
	return 0;
}
