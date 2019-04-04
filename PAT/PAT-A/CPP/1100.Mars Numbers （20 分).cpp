#include <iostream>
using namespace std;

int main(){
	string s1[13] = {"###", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string s2[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	int N, t;
	string temp;
	scanf("%d", &N);
	getchar();
	for(int i = 0; i < N; i++){
		getline(cin, temp);
		if(temp[0] >= '0' && temp[0] <= '9'){
			t = stoi(temp);
			if(t == 0) cout << "tret" << endl;
			else if(t / 13 == 0) cout << s1[t] << endl;
			else if(t / 13 != 0 && t % 13 != 0)cout << s2[t / 13] << " " << s1[t % 13] << endl;
			else cout << s2[t / 13] << endl;
		}else {
			if(temp.length() == 3){
				for(int i = 1; i <= 12; i++){
					if(s1[i] == temp) cout << i << endl;
				}
				for(int i = 1; i <= 12; i++){
					if(s2[i] == temp) cout << i * 13 << endl;
				}
				
			}else{
				string t1 = temp.substr(0, 3);
				string t2 = temp.substr(4, 3);
				int sum = 0;
				for(int i = 1; i <= 12; i++){
					if(s2[i] == t1) sum = sum + i * 13;
				}
				for(int i = 1; i <= 12; i++){
					if(s1[i] == t2) sum = sum + i; 
				}
				cout << sum << endl;
			}
		}
		
	}
	return 0;
}
