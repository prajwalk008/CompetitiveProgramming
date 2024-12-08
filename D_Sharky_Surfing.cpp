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
        ll n,m,l;
        cin>>n>>m>>l;

        vector<ll> hurdPos;
        map<ll,ll> hurdleMap;
        for(int i=0; i<n; ++i){
            ll a,b;
            cin>>a>>b;
            hurdPos.push_back(a-1);
            hurdleMap[a-1]= b-a+1;
        }

        vll powerPos;
        map<ll,priority_queue<ll>> powerMap;
        for(int i=0; i<m; ++i){
            ll a,b;
            cin>>a>>b;
            powerPos.push_back(a);
            powerMap[a].push(b);
        }
        priority_queue<ll> pq; 
        ll currPower=1;
        ll powerUsed=0;
        int j=0;
        bool isSolved=false;
        for(int i=0; i<hurdPos.size(); ++i){
            ll x= hurdPos[i];
            while(j<powerPos.size() && powerPos[j]<=x){
                int z1= powerPos[j];
                while(!powerMap[z1].empty()){
                    int y= powerMap[z1].top();
                    powerMap[z1].pop();
                    pq.push(y);
                }
                j++;
            }
            if(hurdleMap[x]>currPower-1){
                while(!pq.empty()){
                    currPower+=pq.top();
                    pq.pop();
                    powerUsed++;
                    if(currPower>hurdleMap[x]){
                        break;
                    }
                }
                if(pq.empty() && currPower<=hurdleMap[x]){
                    cout<<-1<<endl;
                    isSolved=true;
                    break;
                }
                
            }
            
        }
        if(!isSolved){
            cout<<powerUsed<<endl;
        }
        

        


    }
}