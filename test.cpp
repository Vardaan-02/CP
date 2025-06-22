#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<'\n';return;}

const int M = 998244353;
const int N = 2*1e5+10;

void precalc(){}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    vin(v)
    int ans = 0;
    for(int i=0 ; i<63 ; i++){
        for(int j=0 ; j<n ; j++){
            if((1LL<<i)&v[j]) ans++;
            else if(k>=(1LL<<i)){
                k -= (1LL<<i);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
