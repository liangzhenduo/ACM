#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	char s[4] = "RBG";
	scanf("%d", &n);
	char c[200001];
	scanf("%s", c);
	int l = strlen(c);
	int ans = 0;

	for (int i = 1; i < l; i++) {
		if (c[i] == c[i - 1]) {
			ans++;
			for (int j = 0; j < 3; j++) {
				if (s[j] != c[i - 1] && s[j] != c[i + 1]) {
					c[i] = s[j % 3];
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	puts(c);
}
