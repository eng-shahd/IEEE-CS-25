#include <iostream>
using namespace std;

const int M = 100000;

int main() {
    int n, q;
    cin >> n;
    int* p = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int* f = new int[M + 1]();
    for (int i = 0; i < n; ++i) {
        f[p[i]]++;
    }

    int* ps = new int[M + 1]();
    for (int i = 1; i <= M; ++i) {
        ps[i] = ps[i - 1] + f[i];
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        if (m > M) {
            cout << n << endl;
        } else {
            cout << ps[m] << endl;
        }
    }

    delete[] p;
    delete[] f;
    delete[] ps;
    return 0;
}
