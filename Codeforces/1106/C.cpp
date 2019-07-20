#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a[300000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long sum = 0;
	for (int i = 0; i < n / 2; i++) {
		long long tmp = a[i] + a[n - 1 - i];
		sum += tmp * tmp;
	}
	printf("%lld\n", sum);
	return 0;
}
