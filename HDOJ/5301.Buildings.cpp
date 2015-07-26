#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, x, y;
    while (cin >> n >> m >> x >> y){
        if (n <= 2 || m <= 2){
            cout << 1 << endl;
            continue;
        }
        int ans = (min(n, m) + 1) >> 1;
        if (n == m && n % 2 == 1 && x == y && x == (n + 1) / 2){
            cout << ans - 1 << endl;
            continue;
        }
        int m1 = min(y-1, min(x, n-x+1));
        int m2 = min(m-y, min(x, n-x+1));
        int m3 = min(y, min(m-y+1,x-1));
        int m4 = min(y,min(m-y+1,n-x));
        int m5 = max(max(m1, m2), max(m3, m4));
        ans = max(ans, m5);
        cout << ans << endl;
    }
    return 0;
}
