#include <iostream>
using namespace std;

long long choose2(long long k) {
    return k * (k - 1) / 2;
}

int main() {
    int n;
    long long d;
    cin >> n >> d;

    long long points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    long long count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && points[j] - points[i] <= d) {
            j++;
        }
        long long k = j - i - 1;
        if (k >= 2) {
            count += choose2(k);
        }
    }

    cout << count << endl;
    return 0;
}
