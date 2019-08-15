#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	int n, m, k;
	int h[100];
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < n; i++) {
			scanf("%d", &h[i]);
		}
		bool flag = true;
		for(int i = 0; i < n; i++) {
			if(i == n - 1) break;
			if(h[i] + k >= h[i + 1]) {
				int tmp = h[i] + k - h[i + 1];
				if(tmp >= h[i]) tmp = h[i];
				h[i] -= tmp;
				m += tmp;
			}
			else if(h[i] + k + m >= h[i + 1]) {
				int tmp = h[i + 1] - h[i] - k;
				m -= tmp;
				h[i] += tmp;
			}
			else {
				flag = false;
				break;
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
