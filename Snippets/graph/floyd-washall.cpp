#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<endl;return;}

const int M = 1e9+7;
const int N = 1e5+10;

void precalc(){}

void floyd_Warshall(map<int,vector<pair<int,int>>>& adjList,vector<vector<int>>& distance,int n){
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance[i][j] = min(distance[i][j],distance[i][k] + distance[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distance[i][j] == 1e18) {
				distance[i][j] = -1;
			}
		}
	}
}

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