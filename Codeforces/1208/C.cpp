#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	return b ? gcd(b,a%b) : a;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int r[1000][1000];
	int k = 0;
	for(int p = 0; p < n/4; p++) {
		for(int q = 0; q < n/4; q++) {
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					r[p*4+i][q*4+j] = k++;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d", r[i][0]);
		for(int j = 1; j < n; j++) {
			printf(" %d", r[i][j]);
		}
		puts("");
	}
	return 0;
}
