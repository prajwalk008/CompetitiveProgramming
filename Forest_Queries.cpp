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

void solvekr(){
    ll n,q;
    cin>>n>>q;

    vvi matrix(n,vi(n));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            char t;
            cin>>t;
            if(t=='.'){
                matrix[i][j]=0;
            }
            else{
                matrix[i][j]=1;
            }
        }
    }
    

    vvi preMat(n,vi(n));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            preMat[i][j]=matrix[i][j];
            if(i>0){
                preMat[i][j]+=preMat[i-1][j];
            }
            if(j>0){
                preMat[i][j]+=preMat[i][j-1];
            }
            if(i>0 && j>0){
                preMat[i][j]-=preMat[i-1][j-1];
            }
        }
    }
    

    while(q--){
        //cout<<"00"<<endl;
        ll y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        //cout<<x2<<" "<<y2<<endl;
        x1--;
        x2--;
        y1--;
        y2--;

        ll trees= preMat[y2][x2];
        //cout<<"trees="<<trees<<endl;
        if(x1>0){
            trees-=preMat[y2][x1-1];
        }
        if(y1>0){
            trees-=preMat[y1-1][x2];
        }
        if(x1>0 && y1>0){
            trees+=preMat[y1-1][x1-1];
        }

        cout<<trees<<endl;


    }
}

int main(){
    solvekr();
}