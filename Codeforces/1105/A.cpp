//https://codeforces.com/contest/1105/problem/A
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[1000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int cost = 100000;
	int t = 0;
	for (int j = a[0]; j <= a[n - 1]; j++) {
		int c = 0;
		for (int i = 0; i < n; i ++) {
			if (a[i] > j) {
				c += (a[i] - j - 1);
			}
			else if (a[i] < j) {
				c += (j - a[i] - 1);
			}
		}
		if (c < cost) {
			cost = c;
			t = j;
		}
	}
	printf("%d %d\n", t, cost);
}