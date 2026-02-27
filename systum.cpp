#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oms;

// find_by_order to find the Kth element
// order_of_key to find number of elements smaller than x
// to erase from oms use order_of_key and than by its index find its iterator using find_by_order than erase it

#define MrRoamer() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define chal(i,a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define prin(x) for(int i=0;i<x.size();i++)cout<<x[i]<<" ";cout<<endl;
#define take(x) for(int i=0;i<x.size();i++)cin>>x[i];

//---------------------------------------------------------------------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

void printos(os v);
void printos(os v){ cerr << "[ "; for (ll i : v) { _print(i); cerr << " "; } cerr << "]"; cerr<<'\n';}
void printos(oms v);
void printos(oms v){ cerr << "[ "; for (ll i : v) { _print(i); cerr << " "; } cerr << "]"; cerr<<'\n';}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }


//--------------------------code toh yahan hai-----------------------------------

#define int long long

int sumOfDigitsUpto(int r) {
    if (r <= 0) return 0;
    int ans = 0;
    int pow = 1;
    while (pow <= r) {
        int tot = r / (pow * 10);
        ans +=  tot * 45 * pow;
        int rem = r % (pow * 10);
        int d = rem / pow;
        int right = rem % pow;
        ans += (d * (d - 1) / 2) * pow;
        ans += d * (right + 1);
        pow *= 10;
    }
    return ans;
}

void theProgram() {
    int n;
    cin>>n;
    int digi=1,tot=9,temp=n,r=0;
    while(temp>tot*digi)
    {
        temp-=tot*digi;
        r+=tot;
        digi++;
        tot*=10;
    }
    debug(temp)

    int numAdd=temp/digi;
    numAdd+=r;

    int left=temp-(temp/digi)*digi;
    debug(left)
    string last=to_string(numAdd+1);
    debug(last)

    int ind=0,ans=sumOfDigitsUpto(numAdd); 
    while(left--)
    {
        ans+=last[ind]-'0';
        ind++;
    }

    cout<<ans<<endl;
}

signed main() {
    MrRoamer();
    // jaldi mat karna varna galti karega 
    // constraints joi leje nakar penalty lagse
    // zyada time lage toh switch the question
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t=1;
    cin>>t;
    while(t--){
        theProgram();
    }
    return 0;
}