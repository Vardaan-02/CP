#include <bits/stdc++.h>
using namespace std;

// target: standardized weight W
// nbags: exact number of sacks a buyer can carry
// n: total sacks Golu has
// V: array of sack weights
int bagsSum(int target, int nbags, int n, int* V) {
    // dp[j][s] = # of ways to pick j sacks summing to s
    vector<vector<int>> dp(nbags + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        int w = V[i];
        for (int j = nbags; j >= 1; --j) {
            for (int s = target; s >= w; --s) {
                dp[j][s] += dp[j - 1][s - w];
            }
        }
    }
    return dp[nbags][target];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, N, X;
    cin >> W;           // standardized weight
    cin >> N >> X;      // N = bags-per-buyer, X = total sacks Golu has

    vector<int> V(X);
    for (int i = 0; i < X; ++i) {
        cin >> V[i];
    }

    // KPI: # of ways to bundle exactly N sacks to hit weight W
    cout << bagsSum(W, N, X, V.data()) << "\n";
    return 0;
}
