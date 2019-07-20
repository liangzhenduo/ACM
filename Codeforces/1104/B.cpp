//https://codeforces.com/contest/1104/problem/B
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
	char s[100001];
	scanf("%s", s);
	int t = 0, l = strlen(s);
	stack <char>st;
	for (int i = 0; i < l; i++) {
		if (!st.empty() && st.top() == s[i]) {
			t++;
			st.pop();
		}
		else {
			st.push(s[i]);
		}
	}
	printf("%s\n", t % 2 ? "Yes" : "No");
}