//https://codeforces.com/contest/1105/problem/B
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k, x = 0;
	scanf("%d %d", &n, &k);
	char s[n + 1];
	scanf("%s", s);
	int c[26] = {0};
	for (int l = 0; l < n;) {
		int index = s[l] - 'a';
		int flag = 1, i = 1;
		for (; i < k; i++) {
			if (s[l + i] != s[l]) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			l += i;
		}
		else {
			l += k;
			c[index]++;
		}
	}
	for (int j = 0; j < 26; j++) {
		if (c[j] > x) {
			x = c[j];
		}
	}
	printf("%d\n", x);
}