#include<iostream>
#define MASK(n) (1ll << (n))
#define sz(s) (int)s.size()
using namespace std;
const int MOD = 998244353;

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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int L, R; cin >> L >> R;
        int k = 0;
        while (L * MASK(k + 1) <= R) k++;
        if (k == 0) { cout << k + 1 << " " << R - L + 1 << '\n'; continue;}
        int p = FIND_LARGEST(L, R, [&](int x) {
            return 3 * MASK(k - 1) * x <= R; 
        });
        int ans = 0;
        // cerr << p << " ";
        if (p != -1) ans = 1ll * (p - L + 1) * (k + 1) % MOD;
        else p = L - 1; 
        int p2 = FIND_LARGEST(L, R, [&](int x) {
            return MASK(k) * x <= R; 
        });
        if (p2 != -1) ans = ans + (p2 - p);
        if (ans >= MOD) ans -= MOD;
        cout << k + 1 << " " << ans << '\n';
    }
    return 0;
}
// nhận xét sô sau là bội của số trước, để số lượng nhiều nhất thì số sau bằng 2 lần số trước
// Có trường hợp số sau gấp 3 lần nhưng chỉ có xuất hiện 1 lần, nên ta dựa vào các đó để tính.
