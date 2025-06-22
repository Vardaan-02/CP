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

void printGraph(int n,map<int,vector<int>>& adjList){
    for(int i=0 ; i<n ; i++){
        cout << i << " {";
        for(auto j:adjList[i]) cout << j << " ";
        cout << endl;
    }
}

void printGraphWithWeights(int n,map<int,vector<pair<int,int>>>& adjList){
    for(int i=0 ; i<n ; i++){
        cout << i << " " << "{ ";
        for(auto j:adjList[i]){
            cout << "(" << j.first << "," << j.second << ") ";
        }
        cout << "}" << endl;
    }
}

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