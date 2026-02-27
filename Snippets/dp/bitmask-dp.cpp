#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }
 
const int M = 1e9 + 7;
const int INF = 1e18;

int combine(int curr, int prev, int lsb){
    return 0;
}

int cost(int pos, int i){
    return 0;
}

int new_state_add(int n){
    vector<long long> dp(1<<n, INF);
    dp[0] = 0;

    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int pos = __builtin_popcount(mask);

        for(int i = 0 ; i < n ; i++){
            if(!(mask & (1<<i))){
                int newmask = mask | (1<<i);
                dp[newmask] = min(dp[newmask], dp[mask] + cost(pos, i));
            }
        }
    }
}

int submask(int n){
    int N = (1 << n);   

    vector<int> dp(N, 0);
    dp[0] = 0;

    for(int mask = 0 ; mask < N ; mask++){
        for(int sub = mask ; sub ; sub = (sub-1) & mask){
            int other = mask ^ sub;
            dp[mask] = min(dp[mask], dp[sub] + dp[other]);
        }
    }
}

int prev_state_remove(int n){
    int N = (1 << n);   

    vector<int> dp(N, 0);
    dp[0] = 0;

    for(int mask = 0 ; mask < N ; mask++){

        for(int i = 0 ; i < n ; i++){
            if(mask & (1<<i)){
                int prev = mask ^ (1<<i);
                dp[mask] = combine(dp[mask], dp[prev], i);
            }
        }
    }
}

void solve() {
	
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}