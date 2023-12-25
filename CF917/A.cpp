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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0) {
            cout << 0 << '\n';
            return;
        }
    for (int i = 1; i <= n; i++)
        if (a[i] < 0) cnt++;
    if (cnt % 2 == 0) {
        cout << "1\n1 0\n";
    }
    else cout << 0 << '\n';
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