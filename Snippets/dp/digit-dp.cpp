#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

const int M = 1e9 + 7;
const int INF = 1e18;

int f(int pos, int tight, int prev, int started, string &s, vector<vector<vector<vector<int>>>>& dp){
    if(pos == s.size()) return 1;

    if(dp[pos][tight][prev][started] != -1) return dp[pos][tight][prev][started];

    int limit = tight ? s[pos]-'0' : 9;
    int ans = 0;

    for(int d = 0; d <= limit ; d++){
        int new_tight = tight && (d == limit);

        if(!started){
            if(d == 0) ans += f(pos+1, new_tight, 10, 0, s, dp);
			else ans += f(pos+1, new_tight, d, 1, s, dp);
        }
        else{
            if(d == prev) continue;
            ans += f(pos+1, new_tight, d, 1, s, dp);
        }
    }

    return dp[pos][tight][prev][started] = ans;
}

int solve_one(int x){
    if(x < 0) return 0;
    string s = to_string(x);
	vector<vector<vector<vector<int>>>> dp(20, vector<vector<vector<int>>> (2, vector<vector<int>>(11, vector<int>(2, -1))));
    return f(0, 1, 10, 0, s, dp);
}

void solve() {
	int a, b;
	cin >> a >> b;
	a--;

	r(solve_one(b) - solve_one(a))
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
