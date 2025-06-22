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

vector<int> bellman_ford(vector<pair<pair<int,int>,int>>& edges,int src,vector<bool>& marked,int n,int m){
    vector<int> distance(n,1e18);
    distance[src] = 0;
    
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<m ; j++){
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int dis = edges[j].second;
            if(distance[u]!=1e18 && distance[u]+dis<distance[v]) distance[v] = distance[u] + dis;
        }
    }
 
    for(int i=0 ; i<m ; i++){
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int dis = edges[i].second;
        if(distance[u]!=1e18 && distance[u]+dis<distance[v]) marked[v] = true;
    }
 
    return distance;
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