#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long c[n], to[m];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> to[i];
    }

    int i = 0, j = 0;
    long long r = 0;

    while (i < n) {
        while (j + 1 < m && (to[j + 1] - c[i] >= 0 ? to[j + 1] - c[i] : ci] - to[j + 1]) <= 
                             (to[j] - c[i] >= 0 ? to[j] - ci] : c[i] - to[j])) {
            j++;
        }
        long long d = to[j] - c[i] >= 0 ? to[j] - c[i] : c[i] - to[j];
        if (d > r) {
            r = d;
        }
        i++;
    }

    cout << r << endl;

    return 0;
}
