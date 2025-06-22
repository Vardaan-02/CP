#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<endl;return;}

template<typename Node, typename Update>
struct SegmentTree {
	vector<Node> tree;
	vector<int> arr;
	int n;
	int s;
	SegmentTree(int a_len, vector<int> &a) {
		arr = a;
		n = a_len;
		s = 1;
		while (s < n) s <<= 1;
        s <<= 1;    
		tree.resize(s);
        for(int i=0 ; i<tree.size() ; i++) tree[i] = Node();
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index) 
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void internal_update(int start, int end, int index, int query_index, Update &u) 
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			internal_update(start, mid, 2 * index, query_index, u);
		else
			internal_update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node internal_query(int start, int end, int index, int left, int right) {
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = internal_query(start, mid, 2 * index, left, right);
		r = internal_query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void update(int index, int val) { 
		Update new_update = Update(val);
		internal_update(0, n - 1, 1, index, new_update);
	}
	Node query(int left, int right) {
		return internal_query(0, n - 1, 1, left, right);
	}
};

void precalc(){}

void solve(){}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	precalc();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}