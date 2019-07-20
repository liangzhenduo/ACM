#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, k, d;
	int m[100] = {0};
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		m[d % k]++;
	}
	int res = m[0] / 2 * 2;
	for (int j = 1; j <= k / 2; j++) {
		if (j == k - j) {
			res += m[j] / 2 * 2;
		}
		else {
			res += 2 * min(m[j], m[k - j]);
		}
	}
	printf("%d\n", res);
	return 0;
}
