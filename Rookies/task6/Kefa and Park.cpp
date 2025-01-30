#include <iostream>
#include <vector>
using namespace std;

const int ma = 1000000;
vector<int> t[ma];
int ca[ma];

int n, m, re=0;

void dfs(int n, int p, int c){
    if (ca[n]) c++;
     else c = 0;

    if (c > m) return;

    bool is_leaf = true;
    for (int neighbor : t[n]){
         if (neighbor != p) {
            is_leaf = false;
            dfs(neighbor, n, c);
        }
    }

    if (is_leaf) re++;
}

int main() {


    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> ca[i];

    for (int i = 1; i < n; i++){
            
        int u, v;
        cin >> u >> v;
        
        t[u].push_back(v);
        t[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout<<re<<"\n";
    return 0;
}
