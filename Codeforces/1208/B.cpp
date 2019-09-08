#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a[2000], res = n;
	set<int> s;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int j = 0; j < n; j++) {
		int k = 0;
		for(int i = 0; i < j; i++) {
			if(s.find(a[i]) != s.end()) {
				k = i;
				break;
			}
			else {
				s.insert(a[i]);
			}
		}
		for(int i = n-1; i >= k; i--) {
			if(s.find(a[i]) != s.end()) {
				break;
			}
			else {
				s.insert(a[i]);
			}
		}
		res = min(res, n - int(s.size()));
		s.clear();
	}
	printf("%d\n", res);
	return 0;
}
