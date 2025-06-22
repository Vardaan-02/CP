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

vector<int> dijkstra(map<int,vector<pair<int,int>>>& adjList,pair<int,int> src,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance(n,1e18);
    distance[0] = 0;
    pq.push(src);
    while(!pq.empty()){         
        int dis = pq.top().first;         
        int node = pq.top().second;         
        pq.pop();         
        if(dis > distance[node]) continue;
        for(auto i:adjList[node]) if(distance[i.first] > dis+i.second) {                 
            distance[i.first] = dis+i.second;                 
            pq.push({distance[i.first], i.first});             
        }            
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