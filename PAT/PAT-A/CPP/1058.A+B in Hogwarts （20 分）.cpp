#include <iostream>
using namespace std;

int main(){
	int g1, s1, k1, g2, s2, k2, g, s, k;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	k = (k1 + k2) % 29;
	s = (s1 + s2 + (k1 + k2) / 29) % 17;
	g = g1 + g2 + (s1 + s2 + (k1 + k2) / 29) / 17;
	printf("%d.%d.%d", g, s, k);
	return 0;
}

