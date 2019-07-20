#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int x = 0, y = 0;
	int res = 1;
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (x == a && y == b) {
			continue;
		}
		int l = max(x, y);
		int h = min(a, b);
		if (x == y) {
			res += h >= l ? (h - l) : 0;
		}
		else {
			res += h >= l ? (h - l + 1) : 0;
		}
		x = a, y = b;
	}
	printf("%d\n", res);
	return 0;
}
