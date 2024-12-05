#include <iostream>
using namespace std;

long long f(long long v, int k) {
    long long s = 0, t = 1;
    while (v / t > 0)  {
        s += v / t;
        t *= k;
    }
    return s;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;

    long long l = 1, r = n, ans = n;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (f(m, k) >= n) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
