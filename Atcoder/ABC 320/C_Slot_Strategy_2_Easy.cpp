/**
 * 
 * author: Dimpal Kalita
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
     int n;
     cin>>n;
     string s[3];
     cin>>s[0]>>s[1]>>s[2];
     int ans=1e9;
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               for(int k=0;k<n;k++){
                    if(s[0][i]==s[1][j] && s[1][j]==s[2][k] && s[2][k]==s[0][i]){
                         if(i==j and j==k){
                              ans=min(ans,2*n+min({i,j,k}));
                         }else if(i==j or j==k or k==i){
                              ans=min(ans,n+min({i,j,k}));
                         }else{
                              int mx=max({i,j,k});
                              ans=min(ans,mx);
                         }
                    }
               }
          }
     }
     cout<<(ans==1e9?-1:ans)<<endl;

}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}