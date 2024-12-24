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

bool isSuitable(vll& arr, ll k){
    ll addn=-1;
    int i=0;
    while(i<arr.size()){
        if(i==0){
            if(arr[i]+k<arr[i+1]){
                addn= arr[i]+k;
                i++;
            }
            else{
                i+=2;
            }
        }
        else if(i==arr.size()-1){
            return 1;
        }
        else{
            if(arr[i]+k<arr[i+1]){
                if(addn==-1){
                    addn= arr[i]+k;
                    i++;
                }
                else{
                    return 0;
                }
            }
            else{
                i+=2;
            }
        }
    }
    return 1;
}

void solve(){
    //cout<<"=========="<<endl;
    int n;
    cin>>n;

    vll arr(n);
    inv;

    if(n==1){
        cout<<1<<endl;
    }
    else if(n==2){
        cout<<arr[n-1]-arr[0]<<endl;
    }
    else if(n>2 && n%2==0){
        ll kmax=0;

        for(int i=0; i<n;i+=2){
            ll diff= arr[i+1]-arr[i];
            kmax=max(kmax,diff);
        }

        cout<<kmax<<endl;
    }
    else if(n>2 && n%2!=0){
        ll s=1;
        ll e= arr[n-1];
        ll mid= s+(e-s)/2;
        
        ll k;

        while(s<=e){
            //cout<<"--------"<<endl;
            //cout<<s<<" "<<e<<" "<<mid<<" "<<endl;
            bool flag= isSuitable(arr,mid);
            //cout<<flag<<endl;
            if(flag){
                k=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid= s+(e-s)/2;
        }

        cout<<k<<endl;
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}