/**
 * 
 * author: Dimpal Kalita
 * date: 24/04/2023 12:14:54
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
      ll n,t;
      cin>>n>>t;
      vector<ll> a(n), b(n);
      inp(a);
      inp(b);
      vector<pll> ans;
      for(int i=0;i<n;i++){
            if(a[i]+i<=t){
                  ans.pb({b[i],i+1});
            }
      }

      if(ans.size()==0){
            cout<<-1<<endl;
            return;
      }
      sort(all(ans));
      cout<<ans.back().S<<endl;
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