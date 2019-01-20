#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int a){
	if(a <= 1) return false;
	for(int i = 2; i * i <= a; i++){
		if(a % i == 0) return false;
	}
	return true;
}
int main() {
    int n, d;
    while(scanf("%d", &n) != EOF) {
        if(n < 0) break;
        scanf("%d", &d);
        if(isPrime(n) == false) {
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        do{
            arr[len++] = n % d;
            n = n / d;
        }while(n != 0);
        for(int i = 0; i < len; i++)
            n = n * d + arr[i];
        printf("%s", isPrime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}
