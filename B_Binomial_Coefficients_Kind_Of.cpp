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
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; cout<<endl;}

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

#define mod 1000000007

ll fxn(){

}

void solvekr(){
    ll t;
    cin>>t;

    vll arr(t);
    for(int i = 0; i < t; ++i) cin >> arr[i];

    vll arrk(t);
    for(int i = 0; i < t; ++i) cin >> arrk[i];

    vll ans(1e5+1);
    ans[0]=1;
    ans[1e5]=1;

    ll temp=1;
    for(ll i=1; i<ans.size()-1; i++){
        ll x=temp<<1;

        if(x>mod){
            x%=mod;
        }
        temp=x;

        ans[i]=x;
    }

    //print_v(ans);

    for(ll i=0; i<t; i++){
        ll n= arr[i];
        ll k= arrk[i];

        if(k==0 || k==n){
            cout<<1<<endl;  
        }
        else{
            cout<<ans[k]<<endl;
        }
    }

}


int main(){
    solvekr();  
}