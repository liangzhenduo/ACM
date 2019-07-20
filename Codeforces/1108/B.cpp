#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int d[128];
	scanf("%d", &n);
	int flag[10001] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	int a, b;
	if (n == 2) {
		a = d[0];
		b = d[1];
	}
	else {
		sort(d, d + n);
		if (d[n - 1] == d[n - 2]) {
			a = b = d[n - 1];
		}
		else {
			a = d[n - 1];
			for (int i = 0; i < n - 1; i++) {
				if (a % d[i] == 0 && flag[d[i]] == 0) {
					flag[d[i]] = 1;
					d[i] = 0;
				}
			}
			sort(d, d + n - 1);
			b = d[n - 2];
		}
	}
	printf("%d %d\n", a, b);
}
