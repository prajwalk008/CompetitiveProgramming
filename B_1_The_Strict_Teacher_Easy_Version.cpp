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
#define inv for(int i = 0; i < m; ++i) cin >> arr[i];
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

ll find(ll q1, vector<ll>& arr){
    ll s=0;
    ll e=arr.size()-1;

    ll mid= s+(e-s)/2;

    ll ans=0;
    
    while(s<=e){
        if(arr[mid]<q1){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid= s+(e-s)/2;
    }

    return ans;


}

void solvekr(){
    ll n,m,q;
    cin>>n>>m>>q;

    vll arr(m);
    inv;

    ll q1;
    cin>>q1;

    sort(arr.begin(),arr.end());
    //cout<<"here"<<endl;

    if(q1<arr[0]){
        //cout<<"here"<<endl;
        cout<<arr[0]-1<<endl;
        return;
    }
    if(q1>arr[m-1]){
        cout<<n-arr[m-1]<<endl;
        return;
    }

    ll lb= find(q1,arr);
    ll ub= upper_bound(arr.begin(),arr.end(),q1)-arr.begin();
    

    ll ld= q1-arr[lb];
    ll rd= arr[ub]-q1;

    if(abs(ld-rd)<2){
        cout<<min(ld,rd)<<endl;
        return;
    }
    else{
        ll diff= abs(ld-rd)/2;
        cout<<diff+min(ld,rd)<<endl;
        return;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        //cout<<"t=="<<t<<endl;
        solvekr();
    }
}