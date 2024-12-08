#include <iostream>
using namespace std;

void q(int a[], int l, int h) {
    if (l < h) {
        int p = a[h], i = l - 1;
        for (int j = l; j < h; ++j) {
            if (a[j] <= p) {
                i++;
                int t = a[i];
                a[i] = a[j];
                a[j] = t; 
            }
        }
        int t = a[i + 1];
        a[i + 1] = a[h];
        a[h] = t;
        int m = i + 1;
        q(a, l, m - 1);
        q(a, m + 1, h);
    }
}

int main() {
    int n, k, c = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    q(a, 0, n - 1);
    int i = 0, j = 1;
    while (j < n) {
        int d = a[j] - a[i];
        if (d == k) {

            c++;
            i++;
            j++;
        } else if (d < k) { 
            j++;
        } else {
            i++;
        }
        if (i == j) j++;

    }
    cout << c << endl;

    return 0;
}
