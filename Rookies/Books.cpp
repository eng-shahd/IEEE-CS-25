#include <iostream>
using namespace std;

int f(int n, int t, int a[]) {

    int l = 0, s = 0, m = 0;
    for (int r = 0; r < n; ++r)  {
        s += a[r];

        while (s > t) {
            s -= a[l];
            l++;
        }
        if (r - l + 1 > m) {
            m = r - l + 1;
        }
    }
    return m;
}


int main() {
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; ++i) {

        cin >> a[i];
    }


    cout << f(n, t, a) << endl;
    return 0;
}
