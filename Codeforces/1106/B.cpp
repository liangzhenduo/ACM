#include <bits/stdc++.h>
using namespace std;
int a[100000];
long long c[100000];
vector<pair<int, long long> > dish;
bool cmp(pair<int, long long> p, pair<int, long long> q) {
	if (p.second == q.second) {
		return p.first < q.first;
	}
	return p.second < q.second;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
		dish.push_back(make_pair(i, c[i]));
	}
	sort(dish.begin(), dish.end(), cmp);
	int t, d;
	int index = 0;
	while (m--) {
		scanf("%d %d", &t, &d);
		long long cost = 0;
		if (a[t - 1] >= d) {
			cost += d * c[t - 1];
			a[t - 1] -= d;
		}
		else {
			cost += a[t - 1] * c[t - 1];
			d -= a[t - 1];
			a[t - 1] = 0;
			while (d > 0 && index < n) {
				int i = dish[index].first;
				if (a[i] >= d) {
					cost += d * c[i];
					a[i] -= d;
					d = 0;
				}
				else {
					cost += a[i] * c[i];
					d -= a[i];
					a[i] = 0;
					index++;
				}
			}
			if (index == n && d > 0) {
				cost = 0;
			}
		}
		printf("%lld\n", cost);
	}
	return 0;
}
