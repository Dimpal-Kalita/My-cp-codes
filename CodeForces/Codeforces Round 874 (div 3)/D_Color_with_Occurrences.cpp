/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 15:18:08
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
      string t;
      cin>>t;
      ll n;
      cin>>n;
      vector<string> s(n);
      rep(i,0,n) cin>>s[i];

      vector<pair<pll,ll>>vp;
      // start index, end index, index of the chosen substring

      for(int i=0;i<t.length();i++){
          for(int j=0;j<n;j++){
               ll x= s[j].length();
               if(i+x<=t.length() and t.substr(i,x)==s[j]){
                    vp.pb({{i,i+x-1},j});
               }
          }
      }

      sort(all(vp));

      if(vp.size()==0){
          cout<<-1<<endl;
          return;
      }

      vector<pll> ans;
      ll l=0;
      while(l<t.length()){
          ll ind=0,r=-1;
          ll idx=-1;
          for(auto x: vp){
              if(x.F.F<=l and x.F.S>r){
                  ind=x.F.F;
                  r=x.F.S;
                  idx=x.S;
              }
          }
          if(idx==-1 || r==l-1){
              cout<<-1<<endl;
              return;
          }
          ans.pb({idx,ind});
          l=r+1;
      }
      cout<<ans.size()<<endl;
      for(auto x: ans){
          cout<<x.F+1<<" "<<x.S+1<<endl;
      }
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