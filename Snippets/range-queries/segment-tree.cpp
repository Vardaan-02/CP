#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }

const int M = 1e9 + 7;
const int INF = 1e18;

template<typename Node, typename Update>
struct SegmentTree {
	vector<Node> tree;
	vector<int> arr; // type may change
	int n;
	int s;
	SegmentTree(vector<int> &a) { // change if type updated
		arr = a;
		n = a.size();
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(tree.begin(), tree.end() , Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
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
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, int val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	int val; // may change
	Node1() { // Identity element
		val = 0;	// may change
	}
	Node1(int p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val ^ r.val;  // may change
	}
};

struct Update1 {
	int val; // may change
	Update1(int p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};

// additional methods

// search on segment tree of sorted array to find first target
// int find_first(int start, int end, int index, int target){
// 	if(start == end) return start;

// 	pushdown(index, start, end);

// 	int mid = (start + end)/2;

// 	if(tree[2*index].val >= target) return find_first(start, mid, 2*index, target);
// 	else return find_first(mid+1, end, 2*index+1, target);
// }

// int search_position(int target){
// 	if(tree[1].val < target) return -1;
// 	return find_first(0, n-1, 1, target);
// }

// // search on max() segment tree to find next greater element than target in range left to right 
// int find_first_greater(int start,int end,int index,int left,int right,int target){
// 	if(start>right || end<left) return -1;
// 	if(tree[index].val <= target) return -1;

// 	if(start==end) return start;

// 	int mid=(start+end)/2;

// 	int res = find_first_greater(start,mid,2*index,left,right,target);
// 	if(res!=-1) return res;
// 	return find_first_greater(mid+1,end,2*index+1,left,right,target);
// }
// int make_find_first_greater(int left, int right, int target){
// 	return find_first_greater(0, n-1, 1, left, right, target);
// }


// // count numbers <= x in range
// struct Node2 {
// 	vector<int> v;

// 	Node2() {}

// 	Node2(int x) {
// 		v.push_back(x);
// 	}
// struct Update2 {
// 	int val;
// 	Update2(int p1){ val = p1; }
// 	void apply(Node2 &a) {}
// };
// 	void merge(Node2 &l, Node2 &r) {
// 		v.resize(l.v.size() + r.v.size());
// 		merge(l.v.begin(), l.v.end(), r.v.begin(), r.v.end(), v.begin());
// 	}
// };
// int count_leq(int start,int end,int index,int left,int right,int x){
// 	if(start>right || end<left) return 0;

// 	if(start>=left && end<=right){
// 		return upper_bound(tree[index].v.begin(), tree[index].v.end(), x) - tree[index].v.begin();
// 	}

// 	int mid=(start+end)/2;
// 	return count_leq(start,mid,2*index,left,right,x) + count_leq(mid+1,end,2*index+1,left,right,x);
// }

// int make_count_range(int left,int right,int a,int b){
// 	return count_leq(0,n-1,1,left,right,b) - count_leq(0,n-1,1,left,right,a-1);
// }



void solve() {
    
}


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
