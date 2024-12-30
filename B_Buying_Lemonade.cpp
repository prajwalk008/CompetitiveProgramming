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
    ll n,k;
    cin>>n>>k;

    vll arr(n);
    inv;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++){
        minHeap.push(arr[i]);
    }

    ll minus=0;
    ll cans=0;
    ll presses=0;

    while(!minHeap.empty()){
        ll top= minHeap.top()-minus;
        // cout<<"h"<<presses<<endl;
        // cout<<"top= "<<top<<endl;
        

        if(top<=0){
            minHeap.pop();
            presses++;
        }
        else{
            
            cans+=(top)*minHeap.size();
            presses+=(top)*minHeap.size();
            //cout<<"cans"<<cans<<endl;
            

            if(cans>k){
                cans-=(top)*minHeap.size();
                presses-=(top)*minHeap.size();
                
                presses+=(k-cans);
                
                cans+=(k-cans);
                
                

                cout<<presses<<endl;
                return;


            }
            else if(cans==k){
                cout<<presses<<endl;
                return;
            }

            minus=minHeap.top();
        }

    }

    cout<<presses<<endl;
    return;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}