#include <bits/stdc++.h>
#define task "D"
using namespace std;
const int NTEST = 100;
const int T = 1000;
const int N = 1e5;

int random(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void randTest() {
    ofstream inp(task ".inp");
    int t = 1; inp << t << '\n';
    while (t--) {
        int n = 500;
        inp << n << '\n';
        int t = 1;
        vector<int> tmp(n, 1);
        iota(tmp.begin(), tmp.end(), 1);
        random_shuffle(tmp.begin(), tmp.end());
        for (int i = 0; i < n; i++)
            inp << tmp[i] << ' ';
    }
    inp.close();
}

int main() {
    srand(time(NULL));
    for (int i = 1; i <= NTEST; i++) {
        randTest();
        system(task ".exe");
        system(task "_brute.exe");
        if (system("fc " task".out " task".ans") != 0) {
            cout << "TEST: "<< i << "-> WA!\n";
            return 0;
        }
        cout << "TEST: " << i << "-> AC!\n";
    }
    return 0;
}
