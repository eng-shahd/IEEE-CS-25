#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
      
    }

    int s = 0, e = 0, m = 0;
  
    long long c = 0;

    while (e < n) {
        c += a[e];
        while (c > t) {
            c -= a[s];
            s++;
        }
        m = max(m, e - s + 1);
        e++;
      
    }

    cout << m << endl;
    return 0;
}
