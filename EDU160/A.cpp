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
    string s; 
    cin >> s;
    lli a = 0, b= 0;
    for (int i = 0; i + 1 < sz(s); i++)  {
        a = a * 10 + s[i] - '0';
        if (s[i + 1] != '0') {
            lli b = 0;
            for (int j = i + 1; j < sz(s); j++)
                b = b * 10 + s[j] - '0';
            if (a < b) {
                cout << a << " " << b << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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