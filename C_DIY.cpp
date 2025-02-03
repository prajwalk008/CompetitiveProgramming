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

    vll arr(n);
    inv;

    sort(arr.begin(),arr.end());

    ll xl=INT_MAX;
    ll xh=INT_MIN,yl=INT_MAX,yh=INT_MIN;

    for(ll i=0; i<n-1; i++){
        if(arr[i]==arr[i+1]){
            if(xl==INT_MAX){
                xl=arr[i];

            }
            else if(yl==INT_MAX){
                yl=arr[i];
            }
            else if(yh==INT_MIN){
                yh=arr[i];
            }
            else if(arr[i]>=yh){
                xh=yh;
                yh=arr[i];
            }
            i+=1;
        }
    }

    //cout<<xl<<" "<<yh<<" "<<xl<<" "<<yl<<" "<<xh<<" "<<yl<<" "<<xh<<" "<<yh<<" "<<endl;

    if(xl==INT_MAX || xh==INT_MIN || yl==INT_MAX || yh==INT_MIN){
        no();
        return;
    }
    else{
        ll a1= (xh-xl)*(yh-yl);
        swap(xh,yh);
        ll a2= (xh-xl)*(yh-yl);
        swap(xh,yh);
        swap(xh,yl);
        ll a3= (xh-xl)*(yh-yl);
        swap(xh,yl);

        if(a1>=a2 && a1>=a3){
            yes();
            cout<<xl<<" "<<yh<<" "<<xl<<" "<<yl<<" "<<xh<<" "<<yl<<" "<<xh<<" "<<yh<<" "<<endl;
        }
        else if(a2>=a1 && a2>=a3){
            yes();
            swap(xh,yh);
            cout<<xl<<" "<<yh<<" "<<xl<<" "<<yl<<" "<<xh<<" "<<yl<<" "<<xh<<" "<<yh<<" "<<endl;
        }
        else if(a3>=a1 && a3>=a2){
            yes();
            swap(xh,yl);
            cout<<xl<<" "<<yh<<" "<<xl<<" "<<yl<<" "<<xh<<" "<<yl<<" "<<xh<<" "<<yh<<" "<<endl;


        }

    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvekr();
    }
}