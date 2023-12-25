#include <bits/stdc++.h>
#define task "C"
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 6e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, d, k, a[N], v[N];

void read_input() {
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> v[i];
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= min(40000, d); i++) {
        int res = 0;
        for (int j = 1; j <= n; j++)
            if (a[j] == j) res++;
        ans = max(ans, res + (d - i) / 2);

        for (int j = 1; j <= v[(i - 1) % k]; j++)
            a[j]++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t = 1; cin >> t;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}
