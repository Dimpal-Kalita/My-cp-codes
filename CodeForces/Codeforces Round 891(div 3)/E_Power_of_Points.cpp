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
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     vl temp=v;
     sort(all(v));
     vector<ll>ps(n+1);
     rep(i,0,n){
          ps[i+1]=ps[i]+v[i];
     }
     ll total=ps[n];
     map<ll,ll>mp;
     for(int i=0;i<n;i++){
          ll x=v[i];
          ll ind=upper_bound(all(v),x)-v.begin();
          ll sum=ps[ind]-ps[0];
          ll rem=total-sum;
          ll ans=(ind)*x-sum + rem-(n-ind)*x;
          mp[v[i]]=ans+n;
     }
     for(auto i:temp){
          cout<<mp[i]<<" ";
     }
     cout<<endl;

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