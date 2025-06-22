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

void makeDistance(map<int,vector<int>>& adjList,int src,vector<int>& distance,int n){
    vector<int> visited(n,0);
    queue<pair<int,int>> q;
    q.push({src,0});
    visited[src] = true;
    while(!q.empty()){
        int front = q.front().first;
        int dis = q.front().second;
        distance[front] = dis;
        q.pop();
        for(auto i:adjList[front]){
            if(!visited[i]){
                visited[i]=true;
                q.push({i,dis+1});
            }
        }
    }
}

void dfs(map<int,vector<int>>& adjList,int src,int parent){
    /*
        code
    */
    for(auto i:adjList[src]) if(i!=parent){
        /*
            code
        */
        dfs(adjList,i,src);
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