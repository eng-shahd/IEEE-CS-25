#include <bits/stdc++.h>
using namespace std;

const int mx = 100;

vector<pair<int, int>> adj[mx];
bool visited[mx];
int ma = 0;

void dfs(int node, int current_cost){
       visited[node] = true;

       ma = max(ma, current_cost);

    for (auto [neighbor, cost] : adj[node]) {
    if (!visited[neighbor]) {
        dfs(neighbor, current_cost + cost);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    memset(visited, false, sizeof(visited));
    dfs(0, 0);
    cout << ma << "\n";
    return 0;
}
