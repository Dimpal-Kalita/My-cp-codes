/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 20:09:26
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


void dk(){
     ll n, m;
     cin>>n>>m;
     vector<ll> vis(n,0);
     string s[n];
     for(int i=0;i<n;i++){
          cin>>s[i];
     }

     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if(s[i][j]!= s[0][j]){
                    vis[i]=1;
               }
          }
     }

     ll ans=0;
     for(int i=0;i<n;i++){
          if(!vis[i]) ans++;
     }
     cout<<ans<<endl;
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