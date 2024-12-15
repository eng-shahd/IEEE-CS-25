#include <iostream>
using namespace std;

int c = 0; 
bool a[8], b[15], d[15];

void s(int r, string board[8])  {
    if (r == 8) {
        c++;
        return;
    } 

    for (int col = 0; col < 8; col++)  {
        if (board[r][col] == '.' && !a[col] && !b[r + col] && !d[r - col + 7]) {
            a[col] = b[r + col] = d[r - col + 7] = true;
            s(r + 1, board);
            a[col] = b[r + col] = d[r - col + 7] = false;
         }
     }
 }

int main()  {
    string board[8];
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    s(0, board);
    cout << c << endl;
    return 0;
} 
