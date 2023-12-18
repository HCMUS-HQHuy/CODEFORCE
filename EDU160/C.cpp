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

void read_input() {

}

void solve() {
    int q; cin >> q;
    const int LOG = 30;
    vector<int> done(LOG + 1, 0);
    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 1) done[x] += 1;
        else {
            bool ok = true;
            int t = 0;
            for (int i = 0; i <= LOG; i++) {
                t += done[i];
                if (getBit(x, i)) t--;
                if (t < 0) {
                    ok = false;
                    break;
                }
                t /= 2;
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    int t = 1;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}