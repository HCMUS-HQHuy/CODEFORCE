#include <bits/stdc++.h>
#define task "D"
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 6e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 998244353;


void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

struct FenwickTree {
    int n; vector<int> bit;
    FenwickTree(int n = 0): n(n) {
        bit.assign(n + 1, 0);
    }
    void update(int i, lli val) {
        for (; i <= n; i += i & -i) {
            add(bit[i], val);
            add(bit[i], MOD);
        }
    }
    int get(int i) {
        int ans = 0;
        for (; i > 0; i -= i & -i)
            add(ans, bit[i]);
        return ans;
    }
};

template<class X, class Y> inline bool minimize(X &x, const Y &y) {
    return (x > y ? x = y, true : false);
}

int L[N], R[N], a[N], n;

void read_input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> val;
    for (int i= 1; i <= n; i++)
        val.push_back(a[i]);
    sort(val.begin(), val.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
}

bool ok(int l, int r) {
    int tmp = a[r];
    if (l > 1) minimize(tmp, a[l - 1]);
    for (int i = l; i < r; i++)
        if (a[i] < tmp) return false;
    return true;
}

void solve() {
    
    vector<int> dp(n + 1, 0);

    int min_val = INF;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (ok(j, i)) {
                add(dp[i], dp[j - 1]);
            } 
        }
        // cerr << dp[i] << " ";
    }
    int ans = 0; int tmp = INF;
    for (int i = n; i >= 1; i--) {
        if (minimize(tmp, a[i])) 
            add(ans, dp[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".ans", "w", stdout);
    }
    int t = 1; cin >> t;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}