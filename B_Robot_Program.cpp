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

void solvekr(){
    ll n,x,k;
    cin>>n>>x>>k;

    string s;
    cin>>s;

    ll firstZero=-1,secondZero=-1;
    ll currPos=x;
    ll strPtr=0;
    ll time=1;

    while(strPtr<n && time<=k){
        if(s[strPtr]=='L'){
            currPos--;
        }
        else{
            currPos++;
        }

        if(currPos==0 && firstZero==-1){
            firstZero=time;
            strPtr=0;
        }
        else if(currPos==0 && secondZero==-1){
            secondZero=time;
            strPtr=0;

            ll td= secondZero-firstZero;

            ll tLeft= k-time;

            ll pos= tLeft/td;

            cout<<pos+2<<endl;
            return;
        }
        else if(currPos!=0){
            strPtr++;
        }

        time++;
    }

    if(firstZero==-1){
        cout<<0<<endl;
        return;
    }
    else{
        cout<<1<<endl;
        return;
    }


}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}