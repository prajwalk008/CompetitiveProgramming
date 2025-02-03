#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ll t;
  cin>>t;
  while(t--){
        

        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        bool bo=true;
        for(ll i=0;i<n;i++){
          if(a[i]+b[i]<k){
            bo=false;
            break;
          }
        }
        if(bo){
          cout<<"YES"<<endl;
        }
        else{
          cout<<"NO"<<endl;
        }
    }
  }