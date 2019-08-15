#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	char str[100001];
	char res[11] = "0000000000";
	scanf("%s", str);
	for(int i = 0; i < n; i++) {
		if(str[i] == 'L') {
			for(int j = 0; j < 10; j ++) {
				if(res[j] == '0') {
					res[j] = '1';
					break;
				}
			}
		}
		else if(str[i] == 'R') {
			for(int j = 9; j >= 0; j --) {
				if(res[j] == '0') {
					res[j] = '1';
					break;
				}
			}
		}
		else {
			res[str[i] - '0'] = '0';
		}
	}
	puts(res);
	return 0;
}
