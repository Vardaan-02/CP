#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define endl '\n'
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define sin(a,n) for(int i=0;i<n;i++){int temp;cin>>temp;a.insert(temp);}
#define sout(a) for(auto i:a)cout<< i<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(),greater<int>()

const int M = 1e9+7;
const int N = 1e5+10;

void precalc(){}

class DisjointSet{
	vector<int> size;
	vector<int> parent;

	public:
	DisjointSet(int n){
		parent.resize(n+1);
		size.resize(n+1,1);
		for(int i=0 ; i<=n ;i++) parent[i]=i;
	}

	int getUparent(int n){
		if(n==parent[n]) return n;
		return parent[n] = getUparent(parent[n]);
	}

	void unionBySize(int a,int b){
		int UPa = getUparent(a);
		int UPb = getUparent(b);
		if(UPa==UPb) return;
		if(size[UPa]<size[UPb]){
			parent[UPa] = UPb;
			size[UPb] += size[UPa];
		}
		else{
			parent[UPb] = UPa;
			size[UPa] += size[UPb];
		}
	}

	int getSize(int a){
		return size[getUparent(a)];
	}
};

void solve(){
	
}	

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