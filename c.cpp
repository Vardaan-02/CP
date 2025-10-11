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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<c){
        while(a<c && b>=5){
            if(a-c==b-d) r("YES")
            b -= 5;
            a++;
        }
        if(a-c == b-d && a>=c && b>=d) r("YES")
        else r("NO")
    }
    else{
        while(c<a && a>0){
            if(a-c==b-d) r("YES")
            b += 5;
            a--;
        }
        if(a-c == b-d && a>=c && b>=d) r("YES")
        else r("NO")
    }
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
