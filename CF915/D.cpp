#include <bits/stdc++.h>
#define task "a"
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 6e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

template<class X, class Y> inline bool maximize(X &x, const Y &y) { return (x < y ? x = y, true : false); }

int n;
vector<int> a;

void read_input() {
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void out(stack<pii> st) {
    while (!st.empty()) {
        cout << st.top().first << " " << st.top().second << '\n';
        st.pop();
    }
    cout << '\n';
}

void solve() {
    set<int> se;
    vector<int> mex(n + 1, 0);
    deque<pii> que;
    int p = 0;
    lli ans = 0, sum = 0;
    for (int i = 1; i <= n;i++) {
        se.insert(a[i]);
        while (se.find(p) != se.end()) p++;
        mex[i] = p;
        sum += p;
        que.push_back(make_pair(p, 1));
    }
    ans = sum;
    for (int i = 1; i < n; i++) {
        sum -= que.front().first;
        if (--que.front().second == 0)
            que.pop_front();
        int cnt = 0;
        while (!que.empty() && que.back().first > a[i]) {
            cnt += que.back().second;
            sum -= 1ll * (que.back().first - a[i]) * que.back().second;
            que.pop_back();
        }
        sum += n;
        if (cnt > 0) que.push_back(make_pair(a[i], cnt));
        que.push_back(make_pair(n, 1));
        maximize(ans, sum);
//        out(st);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
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
