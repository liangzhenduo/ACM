#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int w1, h1, w2, h2;
	scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
	printf("%d\n", w1 + w2 + 2 * (h1 + h2) + 4 + (w1 - w2));
	return 0;
}
