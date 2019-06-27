#include <iostream>
#include <vector>
using namespace std;

struct poly{
	int exp;
	double coe;
}; 

int cmp(poly a, poly b){
	return a.exp > b.exp;
}
double result[2000];
int main(){
	int n, m, number = 0;
	cin >> n;
	vector<poly> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].exp >> a[i].coe;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int exp;
		double coe;
		cin >> exp >> coe;
		for(int j = 0; j < n; j++){
			result[exp + a[j].exp] += (coe * a[j].coe);
		}
	}
	for(int i = 0; i <= 2000; i++){
		if(result[i] != 0.0) number++;
	}
	cout << number;
	for(int i = 2000; i >= 0; i--){
		if(result[i] != 0.0)
			printf(" %d %.1f", i, result[i]);
	}
	return 0;	
}
