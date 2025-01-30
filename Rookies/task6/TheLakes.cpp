#include <iostream>
#include <vector>
using namespace std;

int n ;
int m ;
vector<vector<int>>g;
vector<vector<bool>>v;
int dx[]={-1, 1, 0, 0},dy[]={0, 0, -1, 1};

int dfs(int x, int y) {
    v[x][y] = true;
    int s = g[x][y];

    for (int d = 0; d < 4; d++)
    {
    int px = x + dx[d], py = y + dy[d];
    if (px >= 0 && px < n&&py>=0 &&py <m&&!v[px][py] &&g[px][py]>0)
    s += dfs(px, py);
    }
    return s;
}

void solve(){


    cin >> n >> m;
    g.assign(n, vector<int>(m));

    v.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];


    int mx = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (g[i][j] > 0 && !v[i][j])
            mx = max(mx, dfs(i, j));

    cout<<mx<<"\n";
}

int main() {

    int t;
    cin >> t;
        while (t--) solve();
}

