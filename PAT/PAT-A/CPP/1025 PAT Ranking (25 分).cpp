#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student{
	string id;
	int score;
	int location_number;
	int local_rank;
}stu[30010];

bool cmp(Student a, Student b){
	if(a.score != b.score) return a.score > b.score;
	else return a.id < b.id; 
}

int main(){
	int n, k, num = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> stu[num].id >> stu[num].score;
			stu[num].location_number = i;
			num++;
		}
		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;
		for(int j = num - k + 1; j < num; j++){
			if(stu[j].score == stu[j - 1].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
				stu[j].local_rank = j + 1 - (num - k);
		}
	}
	cout << num << endl;
	sort(stu, stu + num, cmp);
	int r = 1;
	for(int i = 0; i < num; i++){
		if(i > 0 && stu[i].score != stu[i - 1].score)
			r = i + 1;
		cout << stu[i].id << " ";
		cout << r << " " << stu[i].location_number << " " << stu[i].local_rank << endl;
	}
	return 0;
}
