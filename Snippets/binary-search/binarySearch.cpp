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

int just_Smaller(vector<int>& v,int target){
	int s = 0;
	int e = v.size()-1;
	int mid = s+(e-s)/2;
	int ans = -1;
	while(s<=e){
		mid = s+(e-s)/2;
		if(v[mid]<target){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}

int just_Larger(vector<int>& v,int target){
	int s = 0;
	int e = v.size()-1;
	int mid = s+(e-s)/2;
	int ans = -1;
	while(s<=e){
		mid = s+(e-s)/2;
		if(v[mid]>target){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ans;
}

void precalc(){}

void solve(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	vin(v);
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