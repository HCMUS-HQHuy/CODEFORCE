#include <bits/stdc++.h>
#define task ""
#define sz(s) (int)s.size()
#define MASK(n) (1ll << (n))
#define getBit(bit, i) (((bit) >> (i)) & 1)
using namespace std;
using lli = long long;
using pii = pair<int, int>;
const int N = 2000 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, k, a[N][N];

void read_input() {
    cin >> n >> k;
}

bool ok() {
    int tmp = 0;
    for (int j =0 ; j < n; j++) tmp ^= a[0][j];
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++)
            cur ^= a[i][j];
        if (cur != tmp) return false;
    }
    tmp = 0;
    for (int j =0 ; j < n; j++) tmp ^= a[j][0];
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++)
            cur ^= a[j][i];
        if (cur != tmp) return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < MASK(n * n); i++) {
        if (__builtin_popcount(i) == k) {
            for (int j = 0; j < n * n; j++) {
                int u = j / n, v = j % n;
                a[u][v] = getBit(i, j);
            }
            if (ok()) {
                cout << "YES\n";
                bool flag = true;
                for (int i = 0; i < n; i++)
                    if (a[i][i] != a[0][0])
                        flag = false;
                if (flag) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) cout << a[i][j];
                        cout << '\n';
                    }
                } 
            }
        }
    }
    cout << "NO\n";
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // if (fopen(task".inp", "r")) {
    //     freopen(task".inp", "r", stdin);
    //     //freopen(task".out", "w", stdout);
    // }
    int t = 1; cin >> t;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}