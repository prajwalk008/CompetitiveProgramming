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
    ll n;
    cin>>n;

    map<ll,ll> isDangerNumber;
    vector<vector<ll>> matrix(n,vector<ll>(2));
    for(ll i=0; i<n; i++){
        cin>>matrix[i][0]>>matrix[i][1];
        if(matrix[i][0]==matrix[i][1]){
            isDangerNumber[matrix[i][0]]++;
        }
    }

    ll m= (2*n)+1;
    vll arr(m);
    ll sum=0;
    for(ll i=1; i<m; i++){
        if(isDangerNumber[i]>0){
            sum++;
            arr[i]=sum;
        }
        else{
            arr[i]=sum;
        }
    }

    string s="";
    for(ll i=0; i<n; i++){
        ll l=matrix[i][0];
        ll r= matrix[i][1];

        if(l==r && isDangerNumber[l]>1){
            s+='0';
        }
        else if(l==r && isDangerNumber[l]==1){
            s+='1';
        }
        else{
            ll range= r-l+1;
            ll diff= arr[r]-arr[l-1];

            if(diff>=range){
                s+='0';
            }
            else{
                s+='1';
            }
        }
    }

    cout<<s<<endl;

    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}