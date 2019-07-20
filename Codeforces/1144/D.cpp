#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, a[200000], cnt[200001] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	int len = 1;
	int res = a[0];
	int index = 0;
	for (int i = 0; i <= 200000; i++) {
		if (cnt[i] > len) {
			res = i;
			len = cnt[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == res) {
			index = i;
			break;
		}
	}
	printf("%d\n", n - len);
	for (int i = index - 1; i >= 0; i--) {
		if (a[i] > res) {
			printf("%d %d %d\n", 2, i + 1, i + 2);
		}
		else {
			printf("%d %d %d\n", 1, i + 1, i + 2);
		}
	}
	for (int i = index + 1; i < n; i++) {
		if (a[i] == res) {
			continue;
		}
		if (a[i] > res) {
			printf("%d %d %d\n", 2, i + 1, i);
		}
		else {
			printf("%d %d %d\n", 1, i + 1, i);
		}
	}
	return 0;
}
