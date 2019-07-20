#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k;
	int a[200005];
	char s[200005];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%s", s);
	long long sum = 0;
	int i, j;
	for (i = 0; i < n; i = j) {
		for (j = i + 1; j <= n; j++) {
			if (j == n || s[j] != s[i]) {
				sort(a + i, a + j);
				for (int l = j - 1, t = 0; t < k && l >= i; l--, t++) {
					sum += a[l];
				}
				break;
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}
