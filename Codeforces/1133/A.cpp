#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int h1, h2, m1, m2;
	scanf("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);
	int s = h1 * 60 + m1;
	int e = h2 * 60 + m2;
	int m = (s + e) / 2;
	int mm = m % 60;
	int hh = m / 60;
	cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << endl;
	return 0;
}
