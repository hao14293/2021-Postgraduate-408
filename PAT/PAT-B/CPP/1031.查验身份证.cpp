#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	string s;
	int wight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
 
	cin >> N;
	int sum, count = 0, is_false;
	for(int i = 0; i < N; i++){
		cin >> s;
		sum = 0;
		is_false = 0;   //注意
		for(int j = 0;j < 17; j++){
			if(s[j] >= '0' && s[j] <= '9')
				sum += (s[j] - '0') * wight[j];
			else{
				is_false = 1;
				break;
			}
		}
		sum = sum % 11;
		if(s[17] != M[sum] || is_false){
			count++;
			cout << s << endl;
		}
	}
	if(count==0)
		cout << "All passed" << endl;
	return 0;
}
