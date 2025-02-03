#include <bits/stdc++.h>
using namespace std;
 #define ll long long

const ll INF = 1e12;

int main(){
	// your code goes here
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,p;
	    cin>>n>>p;
	    vector<int> a(n),l(n),r(n);
	    for(int i =0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    ll h = INF;
	    for(int i =0;i<n;i++){
	        if(a[i]==0){
	            h =0;
	            l[i]=0;
	        }
	          if (a[i] < h){
                l[i] = h;
            }
            else{
                l[i] = a[i];
                h = a[i];
            }
	    }
	    
	    for(int i =n-1;i>=0;i--){
	        if(a[i]==0){
	            r[i]=0;
	            h =0;
	        }
	         if (a[i] < h){
                r[i] = h;
            }
            else{
                r[i] = a[i];
                h = a[i];
            }
	    }
	    
	    for(int i =0;i<n;i++){
	       int mini = min(l[i],r[i]);
	        cout<< (mini + p -1)/p <<" ";
	    }
	    cout<<endl;
	    
	   
	}
    
}