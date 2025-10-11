#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

class SegmentTree{
public:
    vector<int> tree;

    SegmentTree(int n,vector<int>& v){
        tree.resize(4*n+1);
        build(0, n-1, v, 0);
    }


    void build(int s,int e,vector<int>& v,int index){
        if (s == e){tree[index] = v[s]; return;}

        int left = 2*index + 1;
        int right = 2*index + 2;

        int mid = (s+e)/2 ;
        build(s, mid, v, left);
        build(mid+1, e, v, right);

        tree[index] =  min(tree[left], tree[right]);
    }

    int query(int l,int r,int s,int e,int index){
        if(l <= s && e <= r) return tree[index];
        if(l > e || r < s) return INT_MAX;

        int left = 2*index + 1;
        int right = 2*index + 2;

        int mid = (s+e)/2 ;
        int left_contribution = query(l, r, s, mid, left);
        int right_contribution = query(l, r, mid+1, e, right);

        return min(left_contribution, right_contribution);
    }

    void update(int s,int e,int index, int update_index,int val){
        if (s == e && s == update_index) {tree[index] = val; return;}
        if (s > update_index || e < update_index || s >= e) return;

        int left = 2*index + 1;
        int right = 2*index + 2;
        
        int mid = (s+e)/2;
        update(s, mid, left, update_index, val);
        update(mid+1, e, right, update_index, val);

        tree[index] = min(tree[left], tree[right]);
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
