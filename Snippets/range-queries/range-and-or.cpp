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
#define vpin2(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define sin(a,n) for(int i=0;i<n;i++){int temp;cin>>temp;a.insert(temp);}
#define sout(a) for(auto i:a)cout<< i<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(),greater<int>()
#define r(x) {cout<<x<<endl;return;}
#define loop(a,b,i) for(int i=a ; i<b ; i++)

const int M = 1e9+7;
const int N = 1e6+10;

int rangeBitwiseAnd(int left, int right) {
    int cnt = 0;
    while (left != right) {
        left >>= 1;
        right >>= 1;
        cnt++;
    }
    return (left << cnt);
}

int rangeBitwiseOr(int left,int right) {
    int count = 0;
    for (; right && left != right; left >>= 1, right >>= 1, count++);
    for (; count > 0; count--) (left <<= 1)+=1;
    return left;
}

void precalc(){}

void solve(){}

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