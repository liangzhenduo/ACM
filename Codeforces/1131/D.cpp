#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	printf("%d", a[0]);
	for (int i = 2; i < n; i += 2) {
		printf(" %d", a[i]);
	}
	for (int i = n % 2 ? n - 2 : n - 1; i > 0; i -= 2) {
		printf(" %d", a[i]);
	}
	puts("");
	return 0;
}
