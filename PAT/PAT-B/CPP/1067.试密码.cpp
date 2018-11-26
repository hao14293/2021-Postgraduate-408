#include <iostream>
using namespace std;
int main(){
	string pw, temp;
	int n, cnt = 0;
	cin >> pw >> n;
	getchar();
	while(1){
		getline(cin, temp);
		if(temp == "#") break;
		cnt++;
		if(cnt <= n && temp == pw){
			cout << "Welcome in";
			break;
		}else if(cnt <= n && temp != pw){
			cout << "Wrong password: " << temp << endl;
			if(cnt == n){
				cout << "Account locked";
				break;
			}
		}

	}
	return 0;

}
