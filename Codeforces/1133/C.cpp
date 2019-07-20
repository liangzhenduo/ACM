#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	int a[200000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	vector<pair<int, int> > v;
	int sum = 0, l = 1, j = 0;
	int d[200000];
	for (int i = 0; i < n - 1; i++) {
		d[i] = a[i + 1] - a[i];
		sum += d[i];
		l++;
		while (sum > 5) {
			sum -= d[j];
			j++;
			l--;
		}
		v.push_back(make_pair(j, l));
	}
	int res = 1;
	for (int i = 0; i < n - 1; i++) {
		if (v[i].second > res) {
			res = v[i].second;
		}
	}
	printf("%d\n", res);
	return 0;
}
