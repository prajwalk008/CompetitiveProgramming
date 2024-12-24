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

bool isSuitable(vll arr, ll k){
    int addn=-1;
    int addnU=0;
    //cout<<"arr s="<<arr.size()<<endl;
    for(int i=0; i<arr.size(); i++){
        //cout<<"i="<<i<<endl;
        //cout<<"addn="<<addn<<endl;
        if(i==0){
            //cout<<"i==0"<<endl;
            if(arr[i+1]>k+arr[i]){
                //cout<<"arr[i+1]>k+arr[i]"<<endl;
                addn=min(arr[i]+k,arr[i+1]);
                addnU=1;
                //arr[i]=addn;

                if(addn+k<arr[i+1]){
                    return 0;
                }
            }
        }
        else if(i==arr.size()-1){
            //cout<<"i==n-1"<<endl;
            if(addnU){
                if(arr[i]-k>addn){ 
                    addnU=0;
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                if(arr[i]-k>arr[i-1] && addn==-1){ 
                    return 1;
                }
                else if(arr[i]-k>arr[i-1] && addn!=-1){
                    return 0;
                }
                return 1;
            }
            
        }
        else{
            //cout<<"i==mid"<<endl;
            int minD;
            if(addnU){
                minD= min(abs(arr[i]-arr[i+1]),abs(arr[i]-addn));
                addnU=0;
            }
            else{
                minD= min(abs(arr[i]-arr[i+1]),abs(arr[i]-arr[i-1]));
            }
            //cout<<"minD= "<<minD<<endl;

            if(minD>k){
                if(addn==-1){
                    addn= arr[i]+k;
                    addnU=1;

                    if(addn+k<arr[i+1]){
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }

        }
    }

    return 1;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vll arr(n);
        inv;

        //cout<<"========="<<endl;
        if(n==1){
            cout<<1<<endl;
        }
        else if(n==2){
            cout<<arr[1]-arr[0]<<endl;
        }
        else{
            ll s=1;
            ll e= arr[n-1];
            ll mid= s+(e-s)/2;
            
            ll k;

            while(s<=e){
                // cout<<"--------"<<endl;
                // cout<<s<<" "<<e<<" "<<mid<<" "<<endl;
                bool flag= isSuitable(arr,mid);
                //cout<<flag<<endl;
                if(flag){
                    
                    k=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
                mid= s+(e-s)/2;
            }

            cout<<k<<endl;
        }

        
    }
}