#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }
 
const int M = 1e9 + 7;
const int INF = 1e18;

int f(int s, int e, vector<int>& v, vector<vector<int>>& dp){
    if (s > e) return 0;

    if (dp[s][e] != -1) return dp[s][e];

    int mx_index = max_element(v.begin() + s, v.begin() + e + 1) - v.begin();

    int left = f(s, mx_index-1, v, dp);
    int right = f(mx_index+1, e, v, dp);

    return dp[s][e] = max(left, right) + 1;
}

void solve() {
	int n;
	cin >> n;
 
	vector<int> v(n);
	vin(v)

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
 
    r(f(0, n-1, v, dp));
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}