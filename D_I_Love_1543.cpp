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
        int n,m;
        cin>>n>>m;

        vector<string> arr;

        for(int i=0; i<n; ++i){
            string s;
            cin>>s;
            arr.push_back(s);
        }

        int lim= min(n,m);
        int layers= lim/2;

        vector<string> solVector;
        for(int i=0; i<layers; ++i){
            string s1;

            for(int k=i; k<=m-i-1; ++k){
                char t= arr[i][k];
                s1+=t;
            }
            for(int j=i+1; j<n-i-1; ++j){
                char t= arr[j][m-i-1];
                s1+=t;
            }
            for(int k=m-i-1; k>=i; k--){
                char t= arr[n-i-1][k];
                s1+=t;
            }

            for(int j=n-i-2; j>i; j--){
                char t= arr[j][i];
                s1+=t;
            }

            solVector.push_back(s1);
        }

        for(auto &i:solVector){
            string s= i.substr(0,3);
            i+=s;
            //cout<<i<<endl;
        }


        int ans=0;
        for(int i=0; i<solVector.size(); ++i){
            string s= solVector[i];
            for(int j=0; j<s.length()-3; ++j){
                if(s[j]=='1'){
                    string s2= s.substr(j,4);
                    if(s2=="1543"){
                        ans++;
                    }
                }
            }
        }

        cout<<ans<<endl;


    }
}