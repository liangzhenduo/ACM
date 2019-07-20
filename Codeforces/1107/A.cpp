#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int q, n;
	string s;
	cin >> q;
	while (q--) {
		cin >> n >> s;
		if (n == 2 && s[0] >= s[1]) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n2\n";
			cout << s[0] << ' ' << s.substr(1,n-1) << '\n';
		}
	}
	return 0;
}
