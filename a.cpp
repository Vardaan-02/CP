#include <bits/stdc++.h>
using namespace std;


#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }


bool threeSum(vector<int>& nums, int target) {
   int n = nums.size();
   for(int i = 0; i < n; i++) {
       if(i > 0 && nums[i] == nums[i - 1]) continue;
       int j = i + 1, k = n - 1;
       while(j < k) {
           int sum = nums[i] + nums[j] + nums[k];
           if(sum < target) j++;
           else if(sum > target) k--;
           else {
               return true;
               j++, k--;
               while(j < k && nums[j] == nums[j - 1]) j++;
           }
       }
   }
  
   return false;
}

bool twoSum(vector<int>& nums, int target) {
   map<int,int> s;
   for (int i = 0; i<nums.size(); i++) {
       if(s.count(nums[i])>0) return true;
       s[target - nums[i]] = i;
   }
   return false;
}


void solve() {
   int n,k;
   cin >> n >> k;
   vector<int> v(n);
   vector<int> t(n);
   vin(v);
   vin(t);
   vector<int> a;
   vector<int> b;
   for(int i=0 ; i<n ; i++) if(t[i]==8) a.push_back(v[i]); else b.push_back(v[i]);
   int ans = 0;
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   if(threeSum(a,k)) r(k); 
   for(int i=0 ; i<b.size() ; i++) if(twoSum(a,k-b[i])) ans = max(ans,k-b[i]); 
   for(int i=0 ; i<a.size() ; i++) if(twoSum(b,k-a[i])) ans = max(ans,a[i]); 
   cout << ans << endl;
}


int32_t main() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
