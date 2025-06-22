#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define endl '\n'
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first;for(int i=0;i<(a).size();i++)cin>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define sin(a,n) for(int i=0;i<n;i++){int temp;cin>>temp;a.insert(temp);}
#define sout(a) for(auto i:a)cout<< i<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(),greater<int>()

const int M = 1e9+7;
const int N = 1e5+10;

void precalc(){}

int bfs(map<int,vector<int>>& adjList,int src,int dst){
	map<int,bool> visited;
	queue<int> q;
	q.push(src);
	visited[src]=true;
	int ans = 0;
	while(!q.empty()){
		int len = q.size();
		ans++;
		for(int i=0 ; i<len ; i++){
			int front = q.front();
			q.pop();
			for(auto i:adjList[front]){
				if(!visited[i]){
					q.push(i);
					visited[i]=true;
				}
				if(i==dst) return ans;
			}
		}
	}
	return -1;
}

void solve(){
	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// precalc();
	// int t;
	// cin >> t;
	// while(t--){
		solve();
	// }
	return 0;
}