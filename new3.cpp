#include <bits/stdc++.h>


using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// Shortcuts
#define int long long
#define vl vector<long long>
#define pb push_back

#define invl(v, n) rep(i, n) cin >> v[i];


#define rep(i, n) for(int i = 0; i < n; ++i)




void solvekr(){
    int n;
    cin >> n;





    vl arr(n);
    invl(arr, n);





    sort(arr.begin(),arr.end());



    map<int,int> mp;



    for(int i = 0; i < n; ++i){
        mp[arr[i]]++;
    }



    int maxi=INT_MIN;


    for(auto j:mp){
        if(j.second>=2){
            maxi=j.first;
        }
    }










    if(maxi==INT_MIN){
        cout<<-1<<endl;
    }







    else{
        vl ans;
        int c2=0;




        for(int i = 0; i < n; ++i){
            if(arr[i]==maxi && c2<2){
                c2++;
            }
            else{
                ans.pb(arr[i]);
            }
        }






        int mini=INT_MAX;
        int c,d;
        int f=ans.size();




        for(int i = 0; i < f-1; ++i){
            if(mini>ans[i+1]-ans[i]){
                mini=ans[i+1]-ans[i];
                c=ans[i+1];
                d=ans[i];
            }
        }



        if(mini<2*maxi){
            cout<<d<<" "<<c<<" "<<maxi<<" "<<maxi<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}

signed main() {
    FAST_IO
    int t;
    cin >> t;
    while(t--) {
        solvekr();
    }
    return 0;
}