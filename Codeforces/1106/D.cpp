#include <bits/stdc++.h>
using namespace std;
vector<int> g[100001];
bool v[100001];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	set<int> s;
	int x, y;
	while (m--) {
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	s.insert(1);
	v[1] = true;
	while (!s.empty()) {
		int j = *s.begin();
		printf(" %d", j);
		s.erase(j);
		int l = g[j].size();
		for (int i = 0; i < l; i++) {
			if (!v[g[j][i]]) {
				s.insert(g[j][i]);
				v[g[j][i]] = true;
			}
		}
	}
	return 0;
}
