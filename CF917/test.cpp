#include <bits/stdc++.h>
#define task "C"
using namespace std;
const int NTEST = 100;
const int T = 1000;
const int N = 1e5;

int random(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void randTest() {
    ofstream inp(task ".inp");
    inp << 1 << '\n';
    int n = 10, k = random(1, 5), d = random(1, 50);
    inp << n << " " << k << " " << d << '\n';
    for (int i = 1; i <= n; i++)
        inp << random(0, n) << " ";
    inp << '\n';
    for (int i = 1; i <= k; i++)
        inp << random(1, n) << " ";
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
