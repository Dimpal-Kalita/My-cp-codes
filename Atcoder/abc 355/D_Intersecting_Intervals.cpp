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
      map<ll,ll>start,end;
      set<ll>st;
      rep(i,0,n){
          ll l,r;
          cin>>l>>r;
          start[l]++;
          end[r]++;
          st.insert(l);
          st.insert(r);
      }
      ll ans=0,ct=0;
      for(auto i:st){
          if(start.count(i)){
               ans+=ct*start[i];
               ct+=start[i];
               ans+=(start[i]*(start[i]-1))/2;
          }
          if(end.count(i)) ct-=end[i]; 
      }
      cout<<ans<<endl;
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