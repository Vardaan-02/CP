#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }
#define c(x) { cout << x << '\n'; continue; }

const int M = 1e9 + 7;
const int INF = 1e18;
const int LOG = 20;

void solve() {
	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> movies(n);
	for (auto &movie : movies) cin >> movie.first >> movie.second;

	sort(movies.begin(), movies.end());

	vector<int> start(n);
	vector<int> end(n);
	for (int i = 0 ; i < n ; i++) start[i] = movies[i].first;
	for (int i = 0 ; i < n ; i++) end[i] = movies[i].second;

	vector<vector<int>> up(n, vector<int>(LOG, -1));

    for(int i=0;i<n;i++){
        int j = lower_bound(start.begin(), start.end(), end[i]) - start.begin();
        if(j < n) up[i][0] = j;
    }

    for(int k = 1 ; k < LOG ; k++){
        for(int i = 0 ; i < n ; i++){
            if(up[i][k-1] != -1) up[i][k] = up[up[i][k-1]][k-1];
        }
    }

	while (q--){
		int l, r;
		cin >> l >> r;

		int index = lower_bound(start.begin(), start.end(), l) - start.begin();

		if (index == n || end[index] > r) c(0)

		int ans = 1;

        for(int k = LOG-1 ; k >=0 ; k--){
            int next_index = up[index][k];
            if(next_index != -1 && end[next_index] <= r){
                ans += (1LL<<k);
                index = next_index;
            }
        }

        cout << ans << endl;
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
