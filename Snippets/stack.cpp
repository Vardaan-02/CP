#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define endl '\n'
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define sin(a,n) for(int i=0;i<n;i++){int temp;cin>>temp;a.insert(temp);}
#define sout(a) for(auto i:a)cout<< i<<' ';cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(),greater<int>()

const int M = 1e9+7;
const int N = 1e5+10;

void precalc(){}

    vector<int> nextGreaterElement(vector<int>& v){
        int n = v.size();
        stack<int> st;
        vector<int> ans(n, n);
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && v[st.top()] < v[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }  

    vector<int> nextSmallerElement(vector<int>& v){
        stack<int> st;
        vector<int> ans(v.size(),-1);
        for(int i = 0 ; i < v.size() ; i++){
            while(!st.empty() && v[st.top()] > v[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    } 

    vector<int> prevGreaterElement(vector<int>& v){
        stack<int> st;
        vector<int> ans(v.size(),-1);
        for(int i = 0 ; i < v.size() ; i++){
            while(!st.empty() && v[st.top()] < v[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& v){
        stack<int> st;
        vector<int> ans(v.size(),-1);
        for(int i = 0 ; i < v.size() ; i++){
            while(!st.empty() && v[st.top()] > v[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

void solve(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	vin(v);
    vector<int> nxtGreater = prevSmallerElement(v);
    vout(nxtGreater);
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