#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	long long k;
	int x;
	while (n--) {
		scanf("%lld %d", &k, &x);
		long long ans = k * 9 - (9 -x);
		printf("%lld\n", ans);
	}
	return 0;
}
