#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	char m[501][501];
	for (int i = 0; i < n; i++) {
		scanf("%s", m[i]);
	}
	int k = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (m[i][j] == 'X' &&
			    m[i - 1][j - 1] == 'X' &&
			    m[i - 1][j + 1] == 'X' &&
			    m[i + 1][j - 1] == 'X' &&
			    m[i + 1][j + 1] == 'X') {
				k++;
			}
		}
	}
	printf("%d\n", k);
	return 0;
}
