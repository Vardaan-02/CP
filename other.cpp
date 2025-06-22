#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }

    // pos[val] = position of val in A (0-based)
    vector<int> pos(N+1);
    for(int i = 0; i < N; i++){
        pos[A[i]] = i;
    }

    // build the sequence C of positions of B's elements in A
    vector<int> C(N);
    for(int i = 0; i < N; i++){
        C[i] = pos[B[i]];
    }

    // compute length of LIS on C
    // classic patience‐sorting in O(N log N)
    vector<int> tail;
    tail.reserve(N);
    for(int x : C){
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if(it == tail.end())
            tail.push_back(x);
        else
            *it = x;
    }
    int L = tail.size();

    // total deletions = (N - L) from A + (N - L) from B
    long long ans = 2LL * (N - L);
    cout << ans << "\n";

    return 0;
}
