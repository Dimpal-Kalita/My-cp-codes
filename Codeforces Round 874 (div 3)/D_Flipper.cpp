/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 20:55:18
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
      ll n;
      cin>>n;
      vector<ll> v(n);
      inp(v);
      ll mx=0;
      if(n==1){
          cout<<1<<endl;
          return;
      }
      for(int i=1;i<n;i++){
          mx= max(mx,v[i]);
      }
      
      vector<ll> ans,ans2;
      for(int i=0;i<n;i++){
          if(v[i]==mx){
            for(int ind=i-1;ind>=0;ind--){
                    vector<ll> temp;
                    for(int j=i-1;j>=ind;j--){
                        temp.pb(v[j]);
                    }
                    for(int j=0;j<ind;j++){
                        temp.pb(v[j]);
                    }
                    if(temp>ans2) ans2=temp;


            }     
            for(int j=i;j<n;j++){
                ans.pb(v[j]);
            }
            for(auto it:ans2){
                ans.pb(it);
            }
          }
      }

      vector<ll> ans3;
      if(v[n-1]==mx){
          ans3.pb(mx);
          for(int i=0;i<n-1;i++){
               ans3.pb(v[i]);
          }
      }
      if(ans3>ans) swap(ans,ans3);
      for(auto it:ans){
          cout<<it<<" ";
      }
      cout<<endl;

}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}