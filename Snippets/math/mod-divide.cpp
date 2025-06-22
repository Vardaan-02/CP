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

vector<int> factorial(1e5+10,1);

void calc(){ for(int i=2 ; i<=1e5 ; i++) factorial[i] = (factorial[i-1]*i)%M; }

int gcdExtended(int a, int b, int *x, int *y){
	if (a == 0){
		*x = 0, *y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}
 
int modInverse(int b, int m){
	int x, y; 
	int g = gcdExtended(b, m, &x, &y);
	if (g != 1) return -1;
	return (x % m + m) % m;
}

int modDivide(int a, int b, int m){
	a = a % m;
	int inverse = modInverse(b, m);
	if (inverse == -1) return -1;
	else return (inverse * a) % m;
}

int nCr(int n, int r){
	return modDivide(factorial[n],(factorial[r]*factorial[n-r])%998244353,998244353);
}

void precalc(){}

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