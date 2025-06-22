#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(sum) { cout << sum << '\n'; return; }

void solve() {
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    int sum = a+b-1;
    if(sum<=n){
        int ans = sum*(sum-1)/2;
        ans += sum-b+1;
        int x=n-a;
        cout << ans << endl;
    } 
    else{   
        int y=n-b+1;
        int x=n-a+1;
        sum = x+y-1;
        int ans = sum*(sum-1)/2;
        ans += sum-y+1;
        cout << n*n-ans+1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
