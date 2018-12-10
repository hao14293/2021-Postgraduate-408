#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string s, result;
	vector<char> v;
	for(int i = 0; i < 2; i++){
		getline(cin, s);
		for(int j = 0; j < s.length(); j++){
			vector<char>::iterator iter=find(v.begin(), v.end(), s[j]);
			if(iter == v.end()){
				v.push_back(s[j]);
			}
		}
	}
	for(int i = 0; i < v.size(); i++)
	    printf("%c",v[i]);
	return 0;
}


//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//int main(){
//	string s;
//	set<char> v;
//	vector<char> r;
//	for(int i = 0; i < 2; i++){
//		getline(cin, s);
//		for(int j = 0; j < s.length(); j++){
//			if(v.find(s[j]) == v.end()){
//				v.insert(s[j]);
//				r.push_back(s[j]);
//			}
//		}
//	}
//	vector<char>::iterator iter=r.begin();
//	while(iter != r.end()){
//		cout << *iter;
//		++iter;
//	}
//	return 0;
//}
