#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a;
	int cnt[1001] = {0};
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &a);
		cnt[a]++;
	}
	queue<int> q;
	int m = 0;
	if (n % 2 == 1) {
		for (int i = 1; i <= 1000; i++) {
			if (cnt[i] % 2 > 0) {
				m = i;
				cnt[i]--;
				break;
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] % 4 > 0) {
			puts("NO");
			return 0;
		}
		cnt[i] /= 4;
		for (int j = 0; j < cnt[i]; j++) {
			q.push(i);
		}
	}
	puts("YES");
	int matrix[20][20]= {{0}};
	if (n % 2 == 1) {
		matrix[n / 2][n / 2] = m;
		for (int i = 0; i < n / 2; i++) {
			int num = q.front();
			matrix[n / 2][i] = num;
			matrix[n / 2][n - 1 - i] = num;
			matrix[i][n / 2] = num;
			matrix[n - 1 - i][n / 2] = num;
			q.pop();
		}
	}
	int x = 0, y = 0;
	while (!q.empty()) {
		int num = q.front();
		matrix[x][y] = num;
		matrix[n - 1 - x][y] = num;
		matrix[x][n - 1 - y] = num;
		matrix[n - 1 - x][n - 1 - y] = num;
		if (++y == n / 2) {
			x++;
			y = 0;
		}
		q.pop();
	}
	for (int i = 0; i < n; i++) {
		printf("%d", matrix[i][0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", matrix[i][j]);
		}
		puts("");
	}
	return 0;
}
