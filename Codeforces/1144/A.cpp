#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	char str[101];
	while (n--) {
		scanf("%s", str);
		bool flag = true;
		int l = strlen(str);
		sort(str, str + l);
		for (int i = 1; i < l; i++) {
			if (str[i] != str[i - 1] + 1) {
				flag = false;
				break;
			}
		}
		puts(flag ? "Yes" : "No");
	}
	return 0;
}
