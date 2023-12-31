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
    if (a < 0) a += MOD;
}

struct FenwickTree {
    int n; vector<int> bit;
    FenwickTree(int n = 0): n(n) {
        bit.assign(n + 1, 0);
    }
    void update(int i, lli val) {
        for (; i <= n; i += i & -i) {
            add(bit[i], val);
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

int a[N], n;

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

void solve() {
    stack<int> st;
    vector<int> L, R; L = R = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) L[i] = 1;
        else L[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) R[i] = n;
        else R[i] = st.top() - 1;
        st.push(i);
    }

    vector<int> dp(n + 1, 0);
    vector<int> sum(n + 1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    FenwickTree bit(n + 1);

    dp[0] = sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        while (!heap.empty() && heap.top().first + 1 < i) {
            bit.update(heap.top().second, -dp[heap.top().second]);
            heap.pop();
        }
        if (L[i] == 1) add(dp[i], sum[i - 1]);
        else {
            add(dp[i], sum[i - 1] - sum[L[i] - 2]);
            add(dp[i], bit.get(L[i] - 2));
        }
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
        heap.push(make_pair(R[i], i));
        bit.update(i, dp[i]);
        // cerr << sum[i] << " " << dp[i] << "\n";
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
        freopen(task".out", "w", stdout);
    }
    int t = 1; cin >> t;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}