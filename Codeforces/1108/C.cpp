#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	char s[6][4] = {"RGB", "RBG", "GBR", "GRB", "BGR", "BRG"};
	scanf("%d", &n);
	char c[200001];
	scanf("%s", c);
	int l = strlen(c);
	int ans = l;
	int index = 0;
	for (int i = 0; i < 6; i++) {
		int k = 0;
		for (int j = 0; j < l; j++) {
			if (c[j] != s[i][j % 3]) {
				k++;
			}
		}
		if (ans > k) {
			ans = k;
			index = i;
		}
	}
	printf("%d\n", ans);
	for (int j = 0; j < l; j++) {
		printf("%c", s[index][j % 3]);
	}
	puts("");
}
