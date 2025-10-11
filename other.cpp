#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// BFS-based brute force inner-plot finder.
// fence cells are those with manhattan distance == mid.
// we BFS from center avoiding fence cells to collect the inner region.
int getResults(int n, vector<vector<int>>& v) {
    int mid = n / 2;
    vector<vector<char>> isFence(n, vector<char>(n, 0));
    ll fenceSum = 0, totalSum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            totalSum += v[i][j];
            int d = abs(i - mid) + abs(j - mid);
            if (d == mid) {
                isFence[i][j] = 1;
                fenceSum += v[i][j];
            }
        }
    }

    // BFS from center to collect inner cells (cells reachable from center without crossing fence).
    ll innerSum = 0;
    vector<vector<char>> vis(n, vector<char>(n, 0));
    deque<pair<int,int>> q;
    if (!isFence[mid][mid]) { // center should normally not be fence, but check defensively
        q.emplace_back(mid, mid);
        vis[mid][mid] = 1;
        innerSum += v[mid][mid];
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
        auto [r,c] = q.front(); q.pop_front();
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (vis[nr][nc]) continue;
            if (isFence[nr][nc]) continue; // do not cross fence
            vis[nr][nc] = 1;
            innerSum += v[nr][nc];
            q.emplace_back(nr,nc);
        }
    }

    ll outerSum = totalSum - innerSum - fenceSum;
    ll diff = innerSum - outerSum;
    if (diff < 0) diff = -diff;
    return static_cast<int>(diff);
}

// Try parsing with leading T test count.
bool try_with_T(const vector<int>& tokens, vector<int>& out) {
    out.clear();
    size_t p = 0;
    if (tokens.empty()) return false;
    int T = tokens[p++];
    if (T <= 0) return false;
    for (int tc = 0; tc < T; ++tc) {
        if (p >= tokens.size()) return false;
        int n = tokens[p++];
        if (n <= 0) return false;
        long long need = 1LL * n * n;
        if (p + need > tokens.size()) return false;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = tokens[p++];
        out.push_back(getResults(n, mat));
    }
    return p == tokens.size();
}

// Try parsing as consecutive matrices (no leading T).
bool try_without_T(const vector<int>& tokens, vector<int>& out) {
    out.clear();
    size_t p = 0;
    while (p < tokens.size()) {
        if (p >= tokens.size()) return false;
        int n = tokens[p++];
        if (n <= 0) return false;
        long long need = 1LL * n * n;
        if (p + need > tokens.size()) return false;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = tokens[p++];
        out.push_back(getResults(n, mat));
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read all ints (robust against different judge input styles)
    vector<int> tokens;
    int x;
    while (cin >> x) tokens.push_back(x);
    if (tokens.empty()) return 0;

    vector<int> answers;
    if (!try_with_T(tokens, answers)) {
        answers.clear();
        if (!try_without_T(tokens, answers)) {
            // Fallback: try single-case parsing (first token = n), ignore trailing garbage
            int p = 0;
            int n = tokens[p++];
            if (n > 0 && p + 1LL * n * n <= (int)tokens.size()) {
                vector<vector<int>> mat(n, vector<int>(n));
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        mat[i][j] = tokens[p++];
                answers.push_back(getResults(n, mat));
            }
        }
    }

    // Print each result on its own line
    for (int ans : answers) {
        cout << ans << '\n';
    }
    return 0;
}
