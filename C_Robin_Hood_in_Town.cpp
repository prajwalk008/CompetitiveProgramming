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

bool robinHoodApp(ll x, ll sum, ll n, vll arr){
    sum+=x;
    //cout<<"sum= "<<sum<<endl;
    double avg= sum/(n*1.0);

    //cout<<"avg = "<<avg<<endl;

    ll unhappy=0;

    unhappy= lower_bound(arr.begin(),arr.end(),avg/2)-arr.begin();
    //cout<<"unhappy= "<<unhappy<<endl;

    ll half;
    if(n%2==0){
        half= n/2;
    }
    else{
        half= (n-1)/2;
    }

    if(unhappy>half){
        //cout<<"true"<<endl;
        return 1;
    }
    //cout<<"false"<<endl;
    return 0;
}

void solvekr(){
    //cout<<"============"<<endl;
    ll n;
    cin>>n;

    ll sum=0;
    vll arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    //cout<<"sum= "<<sum<<endl;

    sort(arr.begin(),arr.end());
    //print_v(arr);
    

    ll s=0;
    ll e=1e18;

    ll mid= s+(e-s)/2;
    ll ans=-1;

    while(s<=e){
        //cout<<"---------"<<endl;
        arr[n-1]+=mid;
        //print_v(arr);
        //cout<<"s= "<<s<<" "<<"e= "<<e<<" "<<"mid = "<<mid<<endl;;
        if(robinHoodApp(mid,sum,n, arr)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        arr[n-1]-=mid;
        //print_v(arr);
        mid= s+(e-s)/2;
    }

    cout<<ans<<endl;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}