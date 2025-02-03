#include <bits/stdc++.h> 
using namespace std; 
#define fastio()                      \ 
    ios_base::sync_with_stdio(false); \ 
    cin.tie(NULL);                    \ 
    cout.tie(NULL) 
typedef long long ll; 
const ll inf = 1e18; 
const ll mod = 1e9 + 7; 
const ll MOD = 998244353; 
#define int long long 
#define endl '\n' 

signed main() 
{ 
    fastio(); 
    int t; 
    cin >> t; 
    while (t--) 
    { 
        int n; 
        cin >> n; 
        vector<int> v(n); 
        for (int i = 0; i < n; i++) 
            cin >> v[i]; 

        int ans = accumulate(v.begin(), v.end(), 0ll); 

        sort(v.begin(), v.end()); 

        int sum = ans; 
        for (int i = 0; i < n; i++) 
        { 
            sum -= v[i]; 

            ans = max(ans, sum + (i + 1) * (i + 1)); 
        } 

        ans = max(ans, n * n); 

        cout << ans << endl; 
    } 
};


