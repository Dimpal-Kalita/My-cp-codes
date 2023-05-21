/**
 * 
 * author: Dimpal Kalita
 * date: 04/05/2023 20:49:24
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


ll n, k;


ll recur(ll x=0, ll z=0){
     if(x==to_string(n).length()){
          string s=to_string(n);
          set<ll> st;
          rep(i,0,s.length()){
               st.insert(s[i]-'0');
          }
          return (st.size()<=k?n:md);
     }

     ll limit=0;
     if(!z){
         limit=to_string(n)[x]-'0';
     }

     ll ans=md;
     rep(i,limit,10){
          ll val=recur(x+1,(z?z:i==limit));
          ans=min(ans,val);
     }
     return ans;
}


void dk(){
      cin>>n>>k;
      cout<<recur()<<endl;
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