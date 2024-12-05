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
        string num;
        cin>>num;

        int totSum=0;
        int twos=0;
        int threes=0;

        for(int i=0; i<num.length(); ++i){
            int y= num[i]-'0';
            totSum+=y;

            if(y==2){
                twos++;
            }
            if(y==3){
                threes++;
            }

        }

        // cout<<totSum<<endl;
        // cout<<twos<<endl;
        // cout<<threes<<endl;


        int z= totSum%9;
        if(z==0){
            cout<<"YES"<<endl;
        }

        else if(z==2){
            if(twos>=8 || (twos>=5 && threes>=1) || (twos>=2 && threes>=2)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(z==4){
            if(twos>=7 || (twos>=4 && threes>=1) || (twos>=1 && threes>=2)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(z==6){
            if(twos>=6 || (twos>=3 && threes>=1) || (threes>=2)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(z==8){
            if(twos>=5 || (twos>=2 && threes>=1)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

        else if(z==1){
            if(twos>=4 || (twos>=1 && threes>=1)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        

        else if(z==3){
            if(twos>=3 || threes>=1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

        else if(z==5){
            if(twos>=2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(z==7){
            if(twos>=1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }


    }
}