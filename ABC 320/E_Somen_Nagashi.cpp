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
     priority_queue<pll,vector<pll>,greater<pll>>pq;
     set<ll>st;

     rep(i,0,n){
          pq.push({0,i});
          st.insert(i);
     }
     vector<ll>ans(n);

     rep(i,0,m){
          ll t,w,s;
          cin>>t>>w>>s;

          while(!pq.empty() && t>=pq.top().F){
               st.insert(pq.top().S);
               pq.pop();
          }
          if(st.empty()) continue;

          ll ind=*st.begin();
          ans[ind]+=w;
          st.erase(st.begin());
          pq.push({t+s,ind});
     }
     for(auto i:ans) cout<<i<<endl;
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