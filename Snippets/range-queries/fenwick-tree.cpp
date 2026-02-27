#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

const int M = 1e9 + 7;
const int INF = 1e18;

template<typename Node, typename Update>
struct FenwickTree {
    vector<Node> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, Node());
    }

    // internal add
    void update_internal(int idx, Update &u) {
        for (; idx <= n; idx += idx & -idx) u.apply(bit[idx]);
    }

    // prefix query
    Node query_internal(int idx) {
        Node ans = Node();
        for (; idx > 0; idx -= idx & -idx) ans.merge(bit[idx]);
        return ans;
    }

    // external update
    void make_update(int idx, int val) {
        Update u(val);
        update_internal(idx, u);
    }

    // range query
    Node make_query(int l, int r) {
        Node right = query_internal(r);
        Node left  = query_internal(l - 1);
        Node ans;
        ans.merge_range(left, right);
        return ans;
    }
};

struct Node1 {
    int val;
    Node1() { val = 0; }
    Node1(int v) { val = v; }

    // merge another prefix node
    void merge(Node1 &other) {
        val += other.val;
    }

    // compute range value using two prefixes
    void merge_range(Node1 &l, Node1 &r) {
        val = r.val - l.val;
    }
};

struct Update1 {
    int val;
    Update1(int v) { val = v; }

    void apply(Node1 &a) {
        a.val += val;
    }
};

void solve() {
    
}


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
