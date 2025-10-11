#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

void solve() {
    int n;
    cin >> n;
    ordered_set<int> os;
    vector<int> v(n);
    vin(v);
    for (int i = 0 ; i < n ; i++) os.insert(i);
    for (int i = 0 ; i < n ; i++){
        int index;
        cin >> index;
        index--;
        auto it = os.find_by_order(index);
        cout << v[*it] << endl;
        os.erase(it);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}