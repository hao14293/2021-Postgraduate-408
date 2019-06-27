#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu{
	string name;
	char gender;
	string id;
	int grade;
};

int cmp(stu a, stu b){
	return a.grade < b.grade;
}

int main(){
	int n, result = 0;
	cin >> n;
	vector<stu> m, f;
	for(int i = 0; i < n; i++){
		stu s;
		cin >> s.name >> s.gender >> s.id >> s.grade;
		if(s.gender == 'M') m.push_back(s);
		else f.push_back(s);
	}
	sort(m.begin(), m.end(), cmp);
	sort(f.begin(), f.end(), cmp);	
	if(!f.size()){
		printf("Absent\n");
		cout << m[0].name << " " << m[0].id << endl;
		printf("NA\n");
		return 0;
	}
	else 
		cout << f[f.size() - 1].name << " " << f[f.size() - 1].id << endl;
	if(!m.size()){
		printf("Absent\n");
		printf("NA\n");
		return 0;
	}
	else 
		cout << m[0].name << " " << m[0].id << endl;
	cout << f[f.size() - 1].grade - m[0].grade;
	return 0;
}
