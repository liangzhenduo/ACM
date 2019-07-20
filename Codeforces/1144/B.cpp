#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, a;
	vector<int> even, odd;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a % 2) {
			odd.push_back(a);
		}
		else {
			even.push_back(a);
		}
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	int e = even.size();
	int o = odd.size();
	long long sum = 0;
	if (e > o) {
		int d = e - o - 1;
		for (int i = 0; i < d; i++) {
			sum += even[i];
		}
	}
	else {
		int d = o - e - 1;
		for (int i = 0; i < d; i++) {
			sum += odd[i];
		}
	}
	printf("%lld\n", sum);
	return 0;
}
