#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t, a, b, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &n);
		if(n % 3 == 0) {
			printf("%d\n", a);
		}
		else if(n % 3 == 1) {
			printf("%d\n", b);
		}
		else {
			printf("%d\n", a ^ b);
		}
	}
	return 0;
}
