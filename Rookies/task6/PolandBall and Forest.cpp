#include <iostream>
#include <vector>
using namespace std;

const int mx = 10005;
vector<int> tr[mx];
bool h[mx];
int n;


void dfs(int n){
    h[n] = true;
    for (int g : tr[n]){
        if (!h[g]) {
            dfs(g);
    }
  }
}

int main() {


    cin >> n; 

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        tr[i].push_back(p);
        tr[p].push_back(i);
    }

    int tc = 0;

    for (int i = 1; i <= n; i++){
         if (!h[i]){
            tc++;
            dfs(i);
         }
    } 

    cout << tc << "\n";
    return 0;
 }
