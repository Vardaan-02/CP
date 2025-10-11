#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

class SegmentTree{
public:
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int n,vector<int>& v){
        tree.resize(4*n+1);
        lazy.resize(4*n+1);
        for (int i = 0 ; i < 4*n + 1 ; i++) lazy[i] = 0;
        build(0, n-1, v, 0);
    }


    void build(int s,int e,vector<int>& v,int index){
        if (s == e){tree[index] = v[s]; return;}

        int left = 2*index + 1;
        int right = 2*index + 2;

        int mid = (s+e)/2 ;
        build(s, mid, v, left);
        build(mid+1, e, v, right);

        tree[index] = min(tree[left], tree[right]);
    }

    int query(int l,int r,int s,int e,int index){
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(lazy[index]!=0){
            tree[index] += lazy[index];
            if(s != e){
                lazy[left] += lazy[index];
                lazy[right] += lazy[index];
            }
            lazy[index] = 0;
        }

        if(s >= l && e <= r) return tree[index];
        if(s > r || e < l) return LLONG_MAX;

        int mid = (s+e)/2 ;
        int left_contribution = query(l, r, s, mid, left);
        int right_contribution = query(l, r, mid+1, e, right);

        return min(left_contribution, right_contribution);
    }

    void update(int s,int e,int index, int l,int r,int val){
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(lazy[index]!=0){
            tree[index] += lazy[index];
            if(s != e){
                lazy[left] += lazy[index];
                lazy[right] += lazy[index];
            }
            lazy[index] = 0;
        }

        if (s > r || e < l) return;
        if (s >= l && e <= r) {
            tree[index] += val; 
            if(s != e){
                lazy[left] += val;
                lazy[right] += val;
            } 
            return;
        }
        
        int mid = (s+e)/2;
        update(s, mid, left, l, r, val);
        update(mid+1, e, right, l, r, val);

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
