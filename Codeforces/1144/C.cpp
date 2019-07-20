#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, a[200000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	queue<int> inc;
	stack<int> dec;
	sort(a, a + n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (inc.empty() || inc.back() != a[i]) {
			inc.push(a[i]);
		}
		else if (dec.empty() || dec.top() != a[i]) {
			dec.push(a[i]);
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		puts("YES");
		printf("%lu\n", inc.size());
		if (!inc.empty()) {
			printf("%d", inc.front());
			inc.pop();
			while (!inc.empty()) {
				printf(" %d", inc.front());
				inc.pop();
			}
		}
		puts("");
		printf("%lu\n", dec.size());
		if (!dec.empty()) {
			printf("%d", dec.top());
			dec.pop();
			while (!dec.empty()) {
				printf(" %d", dec.top());
				dec.pop();
			}
		}
		puts("");
	}
	else {
		puts("NO");
	}
	return 0;
}
