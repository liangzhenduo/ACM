#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("in.txt", "r", stdin);
	int n;
	int a, b, c, d;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a != c) {
			printf("%d %d\n", a, c);
		}
		else {
			printf("%d %d\n", a, d);
		}
	}
}
