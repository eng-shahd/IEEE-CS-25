#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<string> l;
vector<vector<int>> monster_time;
map<pair<int, int>, pair<pair<int, int>, char>> parent;



vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> dir_chars = {'D', 'U', 'R', 'L'};



pair<int, int> start;
vector<pair<int, int>> mo;


void bfs_monsters(){

    queue<tuple<int, int, int>> q;
    monster_time.assign(n, vector<int>(m, INT_MAX));


    for (auto [mx, my] : mo) {
        q.emplace(mx, my, 0);
        monster_time[mx][my] = 0;
}

    while (!q.empty())

        {
        auto [x, y, time] = q.front(); q.pop();


        for (auto [dx, dy] : directions) {
             int nx = x + dx, ny = y + dy;
             if (nx >= 0 && nx < n && ny >= 0 && ny < m && l[nx][ny] != '#' && monster_time[nx][ny] == INT_MAX) {
                monster_time[nx][ny] = time + 1;
                q.emplace(nx, ny, time + 1);
    }
   }
  }
 }

bool dfs(int x, int y, int time){
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        start = {x, y};
        return true;
    }

     l[x][y] = '#';

    for (size_t i = 0; i < directions.size(); i++) {
        int nx = x + directions[i].first, ny = y + directions[i].second;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && l[nx][ny] == '.' && time + 1 < monster_time[nx][ny]) {
            parent[{nx, ny}] = {{x, y}, dir_chars[i]};
            if (dfs(nx, ny, time + 1)) return true;
         }
      }
    return false;
}

int main(){
    cin >> n >> m;
    l.resize(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (l[i][j] == 'A') start = {i, j};
            else if (l[i][j] == 'M') mo.push_back({i, j});
}
}

    bfs_monsters();

    if (!dfs(start.first, start.second, 0)){
        cout << "NO\n";
        return 0;
}

    cout << "YES\n";
    string path;
    auto [x, y] = start;
    while (parent.count({x, y})){
        auto [px, py] = parent[{x, y}].first;
        path += parent[{x, y}].second;
        x = px, y = py;
}
    reverse(path.begin(), path.end());
    cout << path.length() << "\n" << path << "\n";

    return 0;
  }
