#include<iostream>
#define sz(s) (int)s.size()
using namespace std;

void out(string &a, string &b) {
    if (a[0] == b[0]) {
        cout << "YES\n";
        cout << a[0] << "*\n";
        return;
    }
    if (a.back() == b.back()) {
        cout << "YES\n";
        cout << "*" << a.back() << "\n";
        return;
    }
    for (int i = 1; i < sz(a); i++)
        for (int j = 1; j < sz(b); j++)
            if (a[i] == b[j] && a[i - 1] == b[j - 1]) {
                cout << "YES\n";
                cout << "*" << a[i - 1] << a[i] << "*\n";
                return;
            }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        out(a, b);
    }
    return 0;
}
// Không khó
