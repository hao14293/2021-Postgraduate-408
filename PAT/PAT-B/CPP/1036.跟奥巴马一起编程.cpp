#include <iostream>
using namespace std;
int main(){
	int N, count;
	char c;
	cin >> N >> c;  
	count = N / 2 + N % 2;
	for(int i = 0; i < count; i++){
		if(i == 0 || i == count - 1){
			for(int j = 0; j < N; j++)
				cout << c;
			cout << endl;
		}else{
			for(int j = 0; j < N; j++){
				if(j == 0 || j == N - 1)
					cout << c;
				else
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
