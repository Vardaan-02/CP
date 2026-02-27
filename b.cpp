#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
int ans = 0;

bool vis[7][7];

void dfs(int x, int y, int idx) {

    // If reached destination
    if (x == 6 && y == 0) {
        if (idx == 48) ans++;
        return;
    }

    // If all moves finished but not at destination
    if (idx == 48) return;

    // Corridor pruning (critical)
    if ((x == 0 || vis[x-1][y]) && (x == 6 || vis[x+1][y]) &&
        (y > 0 && !vis[x][y-1]) && (y < 6 && !vis[x][y+1])) return;

    if ((y == 0 || vis[x][y-1]) && (y == 6 || vis[x][y+1]) &&
        (x > 0 && !vis[x-1][y]) && (x < 6 && !vis[x+1][y])) return;

    vis[x][y] = true;

    char c = s[idx];

    if ((c == '?' || c == 'U') && x > 0 && !vis[x-1][y])
        dfs(x-1, y, idx+1);

    if ((c == '?' || c == 'D') && x < 6 && !vis[x+1][y])
        dfs(x+1, y, idx+1);

    if ((c == '?' || c == 'L') && y > 0 && !vis[x][y-1])
        dfs(x, y-1, idx+1);

    if ((c == '?' || c == 'R') && y < 6 && !vis[x][y+1])
        dfs(x, y+1, idx+1);

    vis[x][y] = false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    dfs(0, 0, 0);

    cout << ans << "\n";
    return 0;
}
