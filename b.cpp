#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(sum) { cout << sum << '\n'; return; }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vin(v);
    if(k==1) r("YES")
    vector<int> a = v;
    sort(a.begin(),a.end());
    vector<int> even;
    vector<int> odd;
    for(int i = 0 ; i < k ; i++) even.push_back(a[i]);
    for(int i = 0 ; i < k ; i++) odd.push_back(a[i]);
    if(k&1) even.pop_back();
    else odd.pop_back();
    int even_size = even.size();
    int odd_size = odd.size();
    bool even_possible = true;
    bool odd_possible = true;
    bool shift = true;
    for (int i = 0 ; i < even_size-1 ; i += 2) if(even[i]!=even[i+1]) even_possible = false;
    for (int i = 0 ; i < even_size-1 ; ){
        if(odd[i]!=odd[i+1] && shift){ shift = false; i+=1;}
        else if(odd[i]!=odd[i+1]){odd_possible = false; break;}
        else i+=2;
    }
    if(even_possible){
        int s = 0;
        int e = even_size;
        stack<int> st;
        map<int,int> m;
        int count = 0;
        for(int i = 0 ; i < even_size ; i+=2){
            m[even[i]]++;
            count++;
        }
        for (int i = 0 ; i < n ; i++){
            if(m[v[i]] && count){
                m[v[i]]--;
                count--;
                st.push(v[i]);
            }
            else if(!count && st.top()==v[i]){
                st.pop();
            }
        }
        if(st.empty()) r("YES")
    }
    if(odd_possible){
        cout << "odd_possible : " << odd_possible << endl;
        return;
    }
    r("NO")
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
