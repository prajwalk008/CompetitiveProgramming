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

ll getMaxX(ll xmin,ll xmax, ll ymin,ll ymax, ll kcpy){
    ll s=xmin;
    ll e= xmax;

    ll mid= s+(e-s)/2;
    ll sol=-1;

    while(s<=e){
        
        if(mid*kcpy<=ymax && mid*kcpy>=ymin){
            sol=mid;
            s=mid+1;
        }
        else if(mid*kcpy>ymax){
            e=mid-1;
        }
        else if(mid*kcpy<ymin){
            s= mid+1;
        }

        mid= s+(e-s)/2;
    }

    return sol;
}

ll getMinX(ll xmin,ll xmax, ll ymin,ll ymax, ll kcpy){
    //cout<<"reached getminx"<<endl;
    ll s=xmin;
    ll e= xmax;

    ll mid= s+(e-s)/2;
    ll sol=-1;

    while(s<=e){
        //cout<<"sol= "<<sol<<endl;
        if(mid*kcpy<=ymax && mid*kcpy>=ymin){
            sol=mid;
            e=mid-1;
        }
        else if(mid*kcpy>ymax){
            e=mid-1;
        }
        else if(mid*kcpy<ymin){
            s= mid+1;
        }

        mid= s+(e-s)/2;
    }

    return sol;
}

void solvekr(){
    ll k,l1,l2,r1,r2;
    cin>>k>>l1>>r1>>l2>>r2;

    ll pairs=0;
    ll kcpy=1;
    //cout<<"7"<<endl;
    while(kcpy<1e10){
        //cout<<"kcpy= "<<kcpy<<endl;
        ll lb= getMinX(l1,r1,l2,r2,kcpy);
        //cout<<"lb=" <<lb<<endl;

        if(lb==-1){
            //cout<<"inside if"<<endl;
            kcpy*=k;
        }
        else{
            ll ub= getMaxX(l1,r1,l2,r2,kcpy);
            //cout<<ub<<endl;

            pairs+=(ub-lb+1);
            kcpy*=k;
        }
        //cout<<"outside if"<<endl;

        
    }

    cout<<pairs<<endl;
    //cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}