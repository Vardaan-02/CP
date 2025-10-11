#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

vector<int> findShortestPath(int V, int E, int paths[][3], int pairs[][2], int colorNumber) {
    vector<vector<pair<int,int>>> g(V + 1); // 1-based indexing
    for (int i = 0; i < E; ++i) {
        int u = paths[i][0];
        int v = paths[i][1];
        int w = paths[i][2];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int src = pairs[colorNumber - 1][0];
    int dst = pairs[colorNumber - 1][1];
    if (dst == -1) return {-1};

    const long long INF = numeric_limits<long long>::max();
    vector<long long> dist(V + 1, INF);
    vector<int> prev(V + 1, -1);

    dist[src] = 0;
    using Node = pair<long long,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (u == dst) break;

        for (auto [v, w] : g[u]) {
            long long nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                prev[v] = u;
                pq.push({nd, v});
            }
        }
    }

    if (dist[dst] == INF) return {-1};

    vector<int> path;
    for (int v = dst; v != -1; v = prev[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int V, E;
    cin >> V >> E;
    int paths[100][3];
    for (int i = 0; i < E; ++i)
        cin >> paths[i][0] >> paths[i][1] >> paths[i][2];

    int numPairs = V / 2;
    int pairs[51][2];
    for (int i = 0; i < numPairs; ++i)
        cin >> pairs[i][0] >> pairs[i][1];
    if (V % 2 == 1) {
        int lone;
        cin >> lone;
        pairs[numPairs][0] = lone;
        pairs[numPairs][1] = -1;
    }

    int Q;
    cin >> Q;
    vector<int> res = findShortestPath(V, E, paths, pairs, Q);

    if (res.size() == 1 && res[0] == -1)
        cout << -1 << endl;
    else
        for (size_t i = 0; i < res.size(); ++i)
            cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
    return 0;
}