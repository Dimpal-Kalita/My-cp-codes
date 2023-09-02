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
     ll n,m;
     cin>>n>>m;
     vector<string>v(n);
     rep(i,0,n) cin>>v[i];

     vector<vector<ll>>row(n,vl(26,0));
     vector<vector<ll>>col(n,vl(26,0));

     rep(i,0,n){
        rep(j,0,m){
          row[i][v[i][j]-'a']++;
          col[j][v[i][j]-'a']++;
        }
     }

     for(int _=0;_<2*n;_++){
          vector<ll>r;
          for(int i=0;i<n;i++){
            set<ll>st;
            for(int j=0;j<26;j++){
              if(row[i][j]>0) st.insert(j);
            }
          }


     }
    //  cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}