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
        string s;
        cin>>s;
        int q;
        cin>>q;

        if(s.length()<4){
            while(q--){
                int a,b;
                cin>>a>>b;
                cout<<"NO"<<endl;
            }
        }

        else{
            int req=0;
            for(int i=0; i<s.length()-3; ++i){
                string subs= s.substr(i,4);

                if(subs=="1100"){
                    req++;
                }
            }

            while(q--){
                int a,b;
                cin>>a>>b;

                if(s[a-1]==b+'0'){
                    if(req>0){
                        cout<<"YES"<<endl;
                    }
                    else{
                        cout<<"NO"<<endl;
                    }
                }
                else{
                    if(b==0){
                        if(req>0){
                            string sub1= s.substr(a-1,4);

                            if(sub1=="1100"){
                                req--; 
                            }
                            else{
                                if(a>1){
                                    string sub2= s.substr(a-2,4);
                                    if(sub2=="1100"){
                                        req--;
                                    }

                                }
                            }
                        }

                        s[a-1]='0';

                        if(a>2){
                            string sub3= s.substr(a-3,4);
                            if(sub3=="1100"){
                                req++;
                            }
                            else{
                                if(a>3){
                                    string sub4= s.substr(a-4,4);
                                    if(sub4=="1100"){
                                        req++;
                                    }
                                }
                            }
                        }

                        
                    }
                    else{
                        if(req>0){
                            if(a>2){
                                string sub1= s.substr(a-3,4);
                                if(sub1=="1100"){
                                    req--;
                                }
                                else{
                                    if(a>3){
                                        string sub4= s.substr(a-4,4);
                                        if(sub4=="1100"){
                                            req--;
                                        }
                                    }
                                }
                            }
                        }

                        s[a-1]='1';

                        string sub1= s.substr(a-1,4);
                        if(sub1=="1100"){
                            req++;
                        }
                        else{
                            if(a>1){
                                string sub2= s.substr(a-2,4);
                                if(sub2=="1100"){
                                    req++;
                                }
                            }
                        }
                        
                    }

                    if(req>0){
                        cout<<"YES"<<endl;
                    }
                    else{
                        cout<<"NO"<<endl;
                    }
                }

            }
        }

        

    }
}