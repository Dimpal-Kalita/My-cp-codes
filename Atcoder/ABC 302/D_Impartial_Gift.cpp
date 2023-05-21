/**
 * 
 * author: Dimpal Kalita
 * date: 20/05/2023 17:57:55
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
      ll n,m,d;
      cin>>n>>m>>d;
      vl a(n),b(m);
      inp(a);
      inp(b);
      sort(all(a));
      sort(all(b));
      ll ans=-1;
      for(auto it:a){
          ll ct=upper_bound(all(b),it+d)-b.begin();
          if(ct>=m) ct--;
          if(b[ct]>it+d) ct--;
          if(abs(b[ct]-it)<=d) ans= max(ans,b[ct]+it);
      }
      for(auto it:b){
          ll ct=upper_bound(all(a),it+d)-a.begin();
          if(ct>=n) ct--;
          if(a[ct]>it+d) ct--;
          if(abs(a[ct]-it)<=d) ans= max(ans,a[ct]+it);
      }
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}