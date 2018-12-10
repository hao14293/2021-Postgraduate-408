//#include <bits/stdc++.h>
//using namespace std;
//
//const int maxn = 1e5 + 10;
//
//struct Node{
//    char id[55];
//    int score;
//}node[maxn], s1[maxn], s2[maxn];
//
//Node asd;
//
//struct N3{
//    int room;
//    int ren;
//}num[maxn], endd[maxn];
//
//bool cmpp(const N3& a, const N3& b) {
//    if(a.ren != b.ren)
//        return a.ren > b.ren;
//    else return a.room < b.room;
//}
//
//bool cmp1(const Node& a, const Node& b) {
//    if(a.score != b.score)
//        return a.score > b.score;
//    else return strcmp(a.id, b.id) < 0;
//}
//
//int main() {
//    int N, M;
//    scanf("%d%d", &N, &M);
//    int zlr = 0;
//    for(int i = 1; i <= N; i ++) {
//        scanf("%s%d", asd.id, &asd.score);
//        if(asd.score >= 0 && asd.score <= 100) {
//            zlr ++;
//            node[zlr].score = asd.score;
//            strcpy(node[zlr].id, asd.id);
//        }
//    }
//
//
//    for(int t = 1; t <= M; t ++) {
//        int x;
//        char op[55];
//        scanf("%d %s", &x, op);
//        if(x == 1) {
//            int cnt1 = 0;
//            for(int i = 1; i <= zlr; i ++) {
//                if(node[i].id[0] == op[0]) {
//                    cnt1 ++;
//                    strcpy(s1[cnt1].id, node[i].id);
//                    s1[cnt1].score = node[i].score;
//                }
//            }
//            printf("Case %d: %d %s\n", t, x, op);
//            if(cnt1 == 0)
//                printf("NA\n");
//            else {
//                sort(s1 + 1, s1 + 1 + cnt1, cmp1);
//                for(int i = 1; i <= cnt1; i ++)
//                    printf("%s %d\n", s1[i].id, s1[i].score);
//            }
//        } else if(x == 2) {
//            int lx = strlen(op);
//            int c;
//            int renshu = 0, zf = 0;
//            for(int i = 1; i <= zlr; i ++) {
//                c = 0;
//                for(int j = 0; j < lx; j ++)
//                    if(node[i].id[j + 1] == op[j])
//                        c ++;
//                if(c == lx) {
//                    renshu ++;
//                    zf += node[i].score;
//                }
//            }
//            printf("Case %d: %d %s\n", t, x, op);
//            if(renshu == 0)
//                printf("NA\n");
//            else {
//                printf("%d %d\n", renshu, zf);
//            }
//        } else if(x == 3){
//            for(int kk = 0; kk < maxn; kk ++) {
//                endd[kk].ren = 0;
//                endd[kk].room = 0;
//                num[kk].ren = 0;
//                num[kk].room = 0;
//            }
//            int lc = strlen(op);
//            int d = 0;
//            int nnn = 0;
//            int naa = 0;
//            for(int i = 1; i <= zlr; i ++) {
//                d = 0;
//                for(int j = 0; j < lc; j ++) {
//                    if(node[i].id[j + 4] == op[j])
//                        d ++;
//                }
//                if(d == 6) {
//                    naa ++;
//                    int rec = 0;
//                    for(int h = 1; h <= 3; h ++)
//                        rec = rec * 10 + (node[i].id[h] - '0');
//                    num[rec].room = rec;
//                    num[rec].ren ++;
//                }
//            }
//            printf("Case %d: %d %s\n", t, x, op);
//            if(naa == 0)
//                printf("NA\n");
//            else {
//                for(int r = 0; r <= 999; r ++) {
//                    if(num[r].ren != 0) {
//                        nnn ++;
//                        endd[nnn].ren = num[r].ren;
//                        endd[nnn].room = num[r].room;
//                    }
//                }
//                sort(endd + 1, endd + 1 + nnn, cmpp);
//                for(int u = 1; u <= nnn; u ++)
//                    printf("%d %d\n", endd[u].room, endd[u].ren);
//            }
//        } else printf("Case %d: %d %s\nNA\n", t, x, op);
//    }
//    return 0;
//}


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
 
struct student {
	string studentNo;
	int grade;
	student() {}
	student(string s, int g) :studentNo(s), grade(g) {}
};
 
struct totalStAndGradeOf1Room {
	int people_num = 0;
	int total_grade = 0;
	totalStAndGradeOf1Room() {}
};
 
bool cmpCase1(const student &s1, const student &s2) {
	if (s1.grade == s2.grade)
		return s1.studentNo < s2.studentNo;
	else
		return s1.grade > s2.grade;
}
 
bool cmpCase3(const pair<string, int> &r1, const pair<string, int> &r2) {
	if (r1.second == r2.second)
		return r1.first < r2.first;
	else
		return r1.second > r2.second;
}
 
void case1Print(const vector<student> &students) {
	if (students.size() == 0) {
		cout << "NA" << endl;
		return;
	}
	for (auto iter = students.cbegin(); iter != students.cend(); ++iter)
		cout << iter->studentNo << " " << iter->grade << endl;
}
 
void case1Select(const char &level, const vector<vector<student>> &studentsOf3Level) {
	switch (level) {
	case 'T':
		case1Print(studentsOf3Level[0]);
		break;
	case 'A':
		case1Print(studentsOf3Level[1]);
		break;
	case 'B':
		case1Print(studentsOf3Level[2]);
		break;
	default:
		//若输入的level不存在，打印“NA”
		cout << "NA" << endl;
		break;
	}
}
 
void case2Select(const string &room, const unordered_map<string, totalStAndGradeOf1Room> &rooms) {
	try {
		cout << rooms.at(room).people_num << " " << rooms.at(room).total_grade << endl;
	}
	catch (out_of_range) {
		cout << "NA" << endl;
	}
}
 
void case3Select(const string &date, const unordered_map<string, vector<pair<string, int>>> &dates) {
	try {
		if(dates.at(date).size()==0)
			cout << "NA" << endl;
		else
			for (auto iter = dates.at(date).begin(); iter != dates.at(date).end(); ++iter)
				cout << iter->first << " " << iter->second << endl;
	}
	catch (out_of_range) {
		cout << "NA" << endl;
	}
}
 
int main() {
	//第一行输入考生人数和统计要求的个数
	int N, M;
	cin >> N >> M;
 
	int i;
	//接下来N行，每行给出一个准考证号和分数
	string studentNo, room, date;
	int grade;
	student tempSt;
	//vector<student> origin(N);
	//Case 1: 将三类考生分别存放在studentsOf3Level[0]、...[1]和...[2]中
	vector<vector<student>> studentsOf3Level(3);
	//Case 2: 根据考场建立map，存放考场人数和总分对象，每次累计
	unordered_map<string, totalStAndGradeOf1Room> rooms;
	//Case 3: 根据日期建立unordered_map，再在每个map中根据考场建立unordered_map，存放考生人数
	//因为考生总人数 N<=1e4,所以不需要根据考场和日期建立1e3*1e6=1e9的二维数组，
	unordered_map<string, unordered_map<string,int>> dates;
 
	for (i = 0; i < N; i++) {
		cin >> studentNo >> grade;
		tempSt = student(studentNo, grade);
		//Case 1
		switch (studentNo[0]) {
		case 'T':
			studentsOf3Level[0].push_back(tempSt);
			break;
		case 'A':
			studentsOf3Level[1].push_back(tempSt);
			break;
		case 'B':
			studentsOf3Level[2].push_back(tempSt);
			break;
		}
 
		//Case 2
		room = studentNo.substr(1, 3);
		date = studentNo.substr(4, 6);
		rooms[room].people_num++;
		rooms[room].total_grade += grade;
 
		//Case 3
		dates[date][room]++;
	}
 
	//Case 1: 按照分数非升序、分数相同时准考证增序输出
	for (i = 0; i < 3; i++)
		sort(studentsOf3Level[i].begin(), studentsOf3Level[i].end(), cmpCase1);
	//Case 3:对每个日期下的考场按照人数非升序排序
	unordered_map<string, vector<pair<string,int>>> dates_sorted;
	for (auto iter_date = dates.begin(); iter_date != dates.end(); ++iter_date) {
		for (auto iter_room = iter_date->second.begin(); iter_room != iter_date->second.end(); ++iter_room)
			dates_sorted[iter_date->first].push_back(*iter_room);
		sort(dates_sorted[iter_date->first].begin(), dates_sorted[iter_date->first].end(), cmpCase3);
	}
 
 
	//接下来M行，每行给出一个统计要求,格式为 ：类型 指令
	int type;
	char command_char;
	string command_str;
	for (i = 1; i <= M; i++) {
		cin >> type;
		//打印这是第几个指令，并重复其内容
		cout << "Case " << i << ": " << type << " ";
		//指令分1、2、3三种情况
		switch (type) {
		case 1:
			cin >> command_char;
			cout << command_char << endl;
			case1Select(command_char, studentsOf3Level);
			break;
		case 2:
			cin >> command_str;
			cout << command_str << endl;
			case2Select(command_str, rooms);
			break;
		case 3:
			cin >> command_str;
			cout << command_str << endl;
			case3Select(command_str, dates_sorted);
			break;
		default:
			cout << "NA" << endl;
			break;
		}
	}
 
	return 0;
}

