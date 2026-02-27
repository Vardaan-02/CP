#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

const int M = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vin(v);

    vector<int> comp = v;

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for(int i = 0 ; i < n ; i++) v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin() + 1;

    vout(v)

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
