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
const int MOD = 1e9 + 7;

template<class Func>
int FIND_LARGEST(int L, int R, Func f) {
    int ans = -1;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (f(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    return ans;
}

string s;

void read_input() {
    cin >> s;
}

void solve() {
    cout << sz(s) - FIND_LARGEST(0, sz(s), [&](int mid) {
        int cnt0 = 0;
        for (auto x: s) cnt0 += (x == '0');
        int cnt1 = sz(s) - cnt0;
        for (int i = 0; i < mid; i++) {
            if (s[i] == '0') cnt1--;
            else cnt0--;
        }
        if (min(cnt0, cnt1) >= 0) return true;
        return false;
    }) << '\n';
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