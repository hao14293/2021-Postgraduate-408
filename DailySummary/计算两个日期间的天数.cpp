#include <cstdio>
int month[13][2] = {
		{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31},
		{31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};

bool isLeap(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){
	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	while(scanf("%d%d", &time1, &time2) != EOF){
		if(time1 > time2){
			int temp = time1;
			time1 = time2;
			time2 = temp;
		}
		y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
		y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;
		int ans = 1;
		while(y1 < y2 || m1 < m2 || d1 < d2){
			d1++;
			if(d1 == month[m1][isLeap(y1)] + 1){
				m1++;
				d1 = 1;
			}
			if(m1 == 13){
				y1++;
				m1 = 1;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
