//https://codeforces.com/contest/1104/problem/A
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int k;
	scanf("%d", &k);
	int i = 9;
	for (; i >= 1; i--) {
		if (k % i == 0) {
			break;
		}
	}
	int n = k / i;
	printf("%d\n", n);
	for (int j = 1; j < n; j++) {
		printf("%d ", i);
	}
	printf("%d\n", i);
}