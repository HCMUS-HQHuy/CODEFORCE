#include<iostream>
using namespace std;

int main() {
    string s; 
    for (int i = 1; i <= 1000; i++) {
        if (i % 3 == 0) s.push_back('F');
        if (i % 5 == 0) s.push_back('B');
    }
    // cout << s << "\n";
    int t; cin >> t;
    while (t--) {
        int n; string tmp ;cin >> n >> tmp;
        cout << ((s.find(tmp) != string::npos) ? "YES\n" : "NO\n");
    }
    return 0;
}
// Dễ
