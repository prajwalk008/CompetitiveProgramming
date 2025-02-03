#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <limits>
#include <iomanip>
#include <functional>
#include <utility>
#include <cctype>
#include <cassert>
#include <climits>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define vl vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define invl(v, n) rep(i, n) cin >> v[i];
#define outvl(v) for(auto i:v) cout << i << " "; cout << endl;
#define pii pair<int,int>
#define maxi priority_queue<int>
#define mini priority_queue<int, greater<int>, vector<int>>
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pm cout << "-1" << endl
#define B break
#define C continue
#define ss second
#define ff first
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define sz(x) (int)(x).size()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_range(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, n) for (int i = n - 1; i >= 0; --i)
#define for_each(x, container) for (auto &x : container)
#define mod 1000000007




vector<int> findMaxSmallerRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); 
    set<int> s; 

    for (int i = n - 1; i >= 0; --i) {
        auto it = s.lower_bound(arr[i]);
        if (it != s.begin()) {
            --it; 
            result[i] = *it;
        }

        s.insert(arr[i]);
    }
    return result;
}

void Prajwal() {
    int n;
    cin>>n;
    vl arr(n);
    invl (arr,n);
    vl b=findMaxSmallerRight(arr);
    int mn=INT_MAX;
    rep(i,n){
        if(b[i]!=-1){
            mn=min(mn,arr[i]-b[i]);
        }
    }
    cout<<mn<<endl;
    



}

signed main() {
    FAST_IO;
    int t;
    t=1;
    while (t--) {
        Prajwal();
    }
    return 0;
}