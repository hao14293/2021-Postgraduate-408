#include <iostream>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		for(int j = 1; j < 10; j++){
			string temp = to_string(j * tmp * tmp);
			string s = to_string(tmp);
			int len = s.length();
			if(s == temp.substr(temp.length() - len, len)){
				printf("%d %d\n", j, j * tmp * tmp);
				break;
			}
			if(j == 9) printf("No\n");
		}
	}
	return 0;
}
