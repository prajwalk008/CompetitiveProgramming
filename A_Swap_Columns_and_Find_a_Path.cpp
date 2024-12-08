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
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

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


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vi r1(n);
        for(int i = 0; i < n; ++i) cin >> r1[i];


        vi r2(n);
        for(int i = 0; i < n; ++i) cin >> r2[i];

        ll ans1=0;
        ll r1Max=INT_MIN;
        ll r2Max= INT_MIN;
        ll r1s=0;
        ll r2s=0;

        for(int i=0; i<n; ++i){
            if(r1[i]>r2[i]){
                r1s++;
                ans1+=r1[i];
                r2Max=max(r2Max,r2[i]);
            }
            else if(r1[i]<r2[i]){
                r2s++;
                ans1+=r2[i];
                r1Max=max(r1Max,r1[i]);
            }
            else{
                ans1+=r1[i];
                if(r1s>=r2s){
                    r2s++;
                    r1Max=max(r1Max,r1[i]);
                }
                else{
                    r1s++;
                    r2Max=max(r2Max,r2[i]);
                }
            }
        }
        ll ans2=ans1;
        ll ans3=ans1;
        ans2+=r2Max;
        ans3+=r1Max;
        

        if(r1s>0 && r2s>0){
            ans1+=max(r1Max,r2Max);
            cout<<ans1<<endl;
        }
        else if(r1s==0){
            cout<<ans3<<endl;
        }
        else if(r2s==0){
            cout<<ans2<<endl;
        }

        //cout<<ans<<endl;
    }
}