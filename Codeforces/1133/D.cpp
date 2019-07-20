#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a[200000];
	long double d[200000], b;
	int res = 0, z = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%Lf", &b);
		if (b == 0 && a[i] == 0) {
			d[i] = 1.0 / 0;
			z++;
		}
		else {
			d[i] = b / a[i];
		}
	}
	sort(d, d + n);
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		if (d[i] >= -1e9) {
			break;
		}
		l++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (d[i] <= 1e9) {
			break;
		}
		r--;
	}
	if (l <= r) {
		int len = 1;
		for (int i = l; i < r; i++) {
			if (d[i] == d[i + 1]) {
				len++;
			}
			else {
				res = max(len, res);
				len = 1;
			}
		}
		res = max(len, res);
	}
	printf("%d\n", res + z);
	return 0;
}
