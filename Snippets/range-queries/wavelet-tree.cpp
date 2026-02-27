#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
// #define r(x) { cout << x << '\n'; return; }

const int M = 1e9 + 7;
const int INF = 1e18;


struct WaveletTree {
    int lo, hi;
    WaveletTree *l, *r;
    vector<int> pref; // pref[i] = elements going left among first i

    WaveletTree(vector<int> &arr, int x, int y) {
        lo = x;
        hi = y;
        l = r = nullptr;

        if(arr.empty() || lo == hi) return;

        int mid = (lo + hi) >> 1;

        vector<int> left, right;
        pref.reserve(arr.size() + 1);
        pref.push_back(0);

        for (int v : arr) {
            if (v <= mid) {
                left.push_back(v);
                pref.push_back(pref.back() + 1);
            } else {
                right.push_back(v);
                pref.push_back(pref.back());
            }
        }

        l = new WaveletTree(left, lo, mid);
        r = new WaveletTree(right, mid + 1, hi);
    }

    // kth smallest in [lq,rq]
    int kth(int lq, int rq, int k) {
        if (lq > rq) return -1;
        if (lo == hi) return lo;

        int lb = pref[lq - 1];
        int rb = pref[rq];
        int inLeft = rb - lb;

        if (k <= inLeft) return l->kth(lb + 1, rb, k);
        else return r->kth(lq - lb, rq - rb, k - inLeft);
    }

    // count <= x in [lq,rq]
    int LTE(int lq, int rq, int x) {
        if (lq > rq || x < lo) return 0;
        if (hi <= x) return rq - lq + 1;

        int lb = pref[lq - 1];
        int rb = pref[rq];

        return l->LTE(lb + 1, rb, x) + r->LTE(lq - lb, rq - rb, x);
    }

    // count values in [x,y] inside [lq,rq]
    int count(int lq, int rq, int x, int y) {
        return LTE(lq, rq, y) - LTE(lq, rq, x - 1);
    }
};

void solve(){
    // int n, q;
    // cin >> n >> q;

    // vector<int> v(n);
    // for(int i = 0 ; i < n ; i++) cin >> v[i];

    // int mn = *min_element(v.begin(), v.end());
    // int mx = *max_element(v.begin(), v.end());

    // WaveletTree wt(v, mn, mx);

    // while(q--){
    //     int l, r, a, b;
    //     cin >> l >> r >> a >> b;

    //     cout << wt.count(l, r, a, b) <<endl;
    // }

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];

    vector<int> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for(int &x : v)
        x = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

    WaveletTree wt(v, 1, comp.size());

    while(q--){
        int l, r, a, b;
        cin >> l >> r >> a >> b;

        // convert query value range to compressed
        int L = lower_bound(comp.begin(), comp.end(), a) - comp.begin() + 1;
        int R = upper_bound(comp.begin(), comp.end(), b) - comp.begin();

        if (L > R) cout << 0 << '\n';
        else cout << wt.count(l, r, L, R) << '\n';
	}
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
