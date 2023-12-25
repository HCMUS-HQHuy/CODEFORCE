#include <bits/stdc++.h>
#define task "B"
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 6e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

template<class X, class Y> inline bool maximize(X &x, const Y &y) {
    return (x < y ? x = y, true : false);
}

int n, delay[N], deg[N];
vector<int> nxt[N], pre[N];

void read_input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> delay[i];
        int t = 0; cin >> t;
        while (t--) {
            int v; cin >> v;
            pre[i].push_back(v);
            nxt[v].push_back(i);
            deg[v]++;
        }
    }
}

void solve() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    // cout << "DEG: "; for (int i = 1; i <= n; i++) cout << deg[i] << " "; cout << '\n';
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++)
        val[i] = delay[i];
    // cout << "VAL: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : pre[u]) {
            if (--deg[v] == 0) {
                maximize(val[v], val[u] + 1);
                q.push(v);
            }
        }
    }
    // cout << "\n";

    memset(deg, 0, sizeof deg);
    for (int i = 1; i <= n; i++) {
        deg[i] = sz(pre[i]);
    }

    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++) 
        if (deg[i] == 0) {
            pq.push({val[i], i});
        }
    
    int ans = 0, cnt = 0;
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        // cout << u << " ";
        maximize(ans, delay[u] + cnt);
        cnt++;
        for (int v : nxt[u]) 
            if (--deg[v] == 0) {
                pq.push({val[v], v});
            }
        
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}