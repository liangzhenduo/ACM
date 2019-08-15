#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    return b?gcd(b,a%b):a;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	long long n, m;
  int q;
	scanf("%lld%lld%d", &n, &m, &q);
	long long k = gcd(n, m);
	long long sx, ex, sy, ey;
	while (q--) {
		scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
		long long f = (sx == 1) ? (sy - 1) / (n / k) : (sy - 1) / (m / k);
		long long t = (ex == 1) ? (ey - 1) / (n / k) : (ey - 1) / (m / k);
		puts(f == t ? "YES" : "NO");
	}
	return 0;
}
