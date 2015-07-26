#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
bool vis[MAX<<2];
typedef pair<int, int> Edge;
Edge G[MAX<<2];
int cnt1[MAX], cnt2[MAX];
int deg[MAX];
int n, m;
int dfs(int idx){
    if (idx > m)
        return 1;
    int res = 0;
    bool ok = true;
    Edge* it = &G[idx];
    --deg[it->first];
    --deg[it->second];
    ++cnt1[it->first];
    ++cnt1[it->second];
    if (abs(cnt1[it->first] - cnt2[it->first]) > deg[it->first] ||
        abs(cnt1[it->second] - cnt2[it->second]) > deg[it->second])
            ok = false;
    if (ok)
        res += dfs(idx + 1);
    --cnt1[it->first];
    --cnt1[it->second];
    ok = true;
    ++cnt2[it->first];
    ++cnt2[it->second];
    if (abs(cnt2[it->first] - cnt1[it->first]) > deg[it->first] ||
        abs(cnt2[it->second] - cnt1[it->second]) > deg[it->second])
            ok = false;
    if (ok) res += dfs(idx + 1);
    ok = true;
    --cnt2[it->first];
    --cnt2[it->second];
    ++deg[it->first];
    ++deg[it->second];
    return res;
}
int main(){
    int T;
    scanf(" %d", &T);
    while (T--){
        scanf(" %d %d", &n, &m);
        memset(deg, 0, sizeof(deg));
        int x, y;
        for (int i = 1; i <= m; ++i){
            scanf(" %d %d", &x, &y);
            ++deg[x];
            ++deg[y];
            if (x > y) swap(x, y);
            G[i].first = x;
            G[i].second = y;
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i)
            if (deg[i] & 1)
                ok = false;
        if (!ok){
            puts("0");
            continue;
        }
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        sort(G + 1, G + m + 1);
        int ans = dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
