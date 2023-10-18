#include<iostream> 
using namespace std;
using lli = long long;
const int N =2e5 + 6;
const lli INF = 1e16;

int n, k, x, a[N];
lli dp[N][22];

void read_input() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

template<class X, class Y> inline bool maximize(X &x, const Y &y) {
    return (x < y ? x = y, true : false);
}

void solve() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] >= 0) {    
                maximize(dp[i + 1][j], 0);
                maximize(dp[i + 1][j + 1], 0);
            }
            maximize(dp[i + 1][j], dp[i][j] + a[i + 1] - x);
            maximize(dp[i + 1][j + 1], dp[i][j] + a[i + 1] + x);
        }
    lli ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= 0 && n - i >= k - j; j--)
            maximize(ans, dp[i][j]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        read_input();
        solve();
    }
    return 0;
}