//https://codeforces.com/contest/1104/problem/C
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	char s[1001];
	scanf("%s", s);
	int x = 0, y = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '0') {
			printf("1 %d\n", x % 4 + 1);
			x++;
		}
		else {
			y++;
			switch (y % 4) {
    			case 1 :
					printf("3 1\n");
					break;
    			case 2 :
					printf("3 3\n");
					break;
				case 3 :
					printf("4 1\n");
					break;
				default :
					printf("4 3\n");
					break;
			}
		}
	}
}