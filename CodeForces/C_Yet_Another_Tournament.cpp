/**
 * 
 * author: Dimpal Kalita
 * date: 21/05/2023 16:09:18
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
      ll n,x;
      cin>>n>>x;
      vector<ll> v(n),v1;
      inp(v);
      v1=v;
      sort(all(v));
      vector<ll> ps(n+1,0);
      rep(i,0,n) ps[i+1]=ps[i]+v[i];

      auto check=[&](ll k)->bool{
               if(k==0) return 0;
               if(k==n+1) return 1;
               if(x>= ps[n-k+1]) return 1;
               if(k==n) return 0;

               // for wining against kth position 
               // he may obtain same score as kth element or
               // defeat the kth element and get a point higher than him
               
               ll pos=n-k;
               pos=lower_bound(all(v),v1[pos])-v.begin();
               ll cost=0;
               if(pos<n-k){
                    cost+= ps[n-k];
               }else{
                    cost+= ps[n-k-1]+v[pos];
               }
          return cost<=x;
      };

      ll l=0,r=n+1;
      while(l<r){
          ll mid=(l+r)/2;
          if(check(mid))
              r=mid;
          else
             l=mid+1;
      }
      cout<<r<<endl;
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