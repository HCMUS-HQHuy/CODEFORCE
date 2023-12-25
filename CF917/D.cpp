#include <bits/stdc++.h>
#define task ""
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
    void update(int i, int val) {
        for (; i > 0; i -= i & -i)
            add(bit[i], val);
    }
    int get(int i) {
        int ans = 0;
        for (; i <= n; i += i & -i)
            add(ans, bit[i]);
        return ans;
    }
};

int n, k, a[N], b[N];

void read_input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++) 
        cin >> b[i];
}

int cal(int a[], int delta) {
    FenwickTree bit(k + 2);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        add(ans, bit.get(a[i] + 1 + delta));
        bit.update(a[i] + 1, 1);    
    }
    cout << ans << '\n';
    return ans;
}

int highest_bit(int x) {
    int ans = 0;
    while (x > 0) {
        ans++;
        x >>= 1;
    }
    return ans;
}

void solve() {
    FenwickTree bit(2 * n);
    int ans = 0;
    const int LOG = 30;
    vector<int> inver(LOG + 1, 0), high_bit(LOG + 1, 0);
    for (int i = 0; i <= LOG; i++) 
        inver[i] = cal(b, i);

    for (int i = 1; i <= n; i++) {
        int hb = highest_bit(a[i]); 
        int cnt = 0;
        for (int i = 0; i < hb ; i++) {
            add(ans, 1ll * inver[hb - i + 1] * high_bit[i] % MOD);
            cnt += high_bit[i];
        }
        add(ans, 1ll * (i - bit.get(a[i] + 1) - cnt) *  inver[1] % MOD);
        cnt += (i - bit.get(a[i]) - cnt);
        add(ans, 1ll * (i - cnt) * inver[0] % MOD);

        high_bit[hb]++;
    }
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