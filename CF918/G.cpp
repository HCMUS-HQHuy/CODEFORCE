#include <bits/stdc++.h>
#define task ""
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 1005;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, val[N], dis[N][N];
vector<pii> adj[N];

void read_input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 1; i <= n; i++) 
        memset(dis[i], 0, sizeof dis[i]);

    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
}

template<class X, class Y> inline bool minimize(X &x, const Y &y) {
    return (x > y ? x = y, true : false);
}

void solve() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < N; j++)
            dis[i][j] = INF;
    dis[1][val[1]] = 0;
    pq.push(make_pair(0, make_pair(1, val[1])));
    while (!pq.empty()) {
        pii u; int cost; tie(cost, u) = pq.top(); pq.pop();   
        for (auto node: adj[u.first]) {
            int v, c; tie(v, c) = node;
            if (minimize(dis[v][min(u.second, val[v])], cost + u.second * c))
                pq.push(make_pair(dis[v][min(u.second, val[v])], make_pair(v, min(u.second, val[v]))));
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++)
        minimize(ans, dis[n][i]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    int t = 1; cin >> t;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}