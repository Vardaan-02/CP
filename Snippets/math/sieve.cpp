#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<endl;return;}

const int M = 1e9+7;
const int N = 1e6+10;
vector<bool> prime(N,true);

void sieve(){
    prime[0]=false;prime[1]=false;
	for(int i=2 ; i*i<=N ; i++) if(prime[i]) for(int j=i*i ; j<=N+10 ; j+=i) prime[j]=false;
}

void precalc(){}

void solve(){}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	precalc();
	int t;
	cin >> t;
	sieve();
	while(t--){
		solve();
	}
	return 0;
}