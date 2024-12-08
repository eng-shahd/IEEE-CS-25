#include <iostream>
using namespace std;

int main() {
    int n;
    cin >>  n;
    int t[n];
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int i = 0, j =  n - 1;
    int a_time = 0, b_time = 0;
    int a_bars = 0, b_bars = 0;

    while (i <= j) {

        if (a_time <= b_time) {
            a_time += t[i];
            a_bars++;
            i++;
        } else {
            b_time += t[j];

            b_bars++;
            j--;
        }

    }

    cout << a_bars << " " << b_bars << endl;
    return 0;
}
