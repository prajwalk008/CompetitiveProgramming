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

ll fun(vector<ll>& brr, ll minBound, ll currVal){
    ll s=0; 
    ll e=brr.size()-1;
    ll mid= s+(e-s)/2;

    ll ans=-1;

    while(s<=e){
        if(brr[mid]-currVal>=minBound){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid= s+(e-s)/2;
    }

    return ans;
}

void solvekr(){
    ll n,m;
    cin>>n>>m;

    vll arr(n);
    inv;

    vll brr(m);
    for(auto &it:brr){
        cin>>it;
    }
    sort(brr.begin(),brr.end());

    for(ll i=0; i<n; i++){  
        if(i==0){
            ll x= fun(brr,INT64_MIN, arr[i]);
            if(x!=-1){
                ll z= brr[x]-arr[i];
                arr[i]=min(arr[i],z);
            }
            
        }   
        else{
            ll x= fun(brr,arr[i-1],arr[i]);
            ll y= arr[i];

            if(x!=-1){
                ll z= brr[x]-y;
                if(max(z,y)<arr[i-1]){
                    no();
                    return;
                }
                else if(min(z,y)>=arr[i-1]){
                    arr[i]=min(z,y);
                }
                else if(z<=y){
                    arr[i]=y;
                }
                else if(y<z){
                    arr[i]=z;
                }
            }
            else{
                if(arr[i]<arr[i-1]){
                    no();
                    return;
                }
            }

            
        }   
        
    }
    //print_v(arr);

    yes();
    

     
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}