#include <bits/stdc++.h>
using namespace std;

//dt
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

//fxns
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define inv for(int i = 0; i < n; ++i) cin >> arr[i];
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

//v-print
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; cout<<endl;}

//utils
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

vector<ll> maxSlidingWindow(vector<ll>& nums, int k) {
    deque<ll> dq;  // Stores indices of useful elements
    vector<ll> result;

    for (int i = 0; i < nums.size(); i++) {
        
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        
        dq.push_back(i);

        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

void solvekr(){
    ll n,d,k;
    cin>>n>>d>>k;

    vll arr(n,0);

    while(k--){
        ll l,r;
        cin>>l>>r;

        l--;
        r--;

        arr[l]+=1;
        if(r<n-1){
            arr[r+1]-=1;
        }
    }

    ll maxEleIdx=0;
    for(ll i=1; i<n; i++){
        arr[i]+=arr[i-1];
        if(i<=n-d && arr[i]>arr[maxEleIdx]){
            maxEleIdx=i;
        }
    }

    ll broVisit=maxEleIdx;

    vll momVisit=maxSlidingWindow(arr,d);

    ll momVisitsOn=0;

    for(ll i=0; i<n-d; i++){
        if(momVisit[i]<momVisit[momVisitsOn]){
            momVisitsOn=i;
        }
    }

    cout<<broVisit+1<<" "<<momVisitsOn+1<<endl;






}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}