/**
 * 
 * author: Dimpal Kalita
 * date: 24/04/2023 21:21:10
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

vector<ll> mp(1e6+1,0);

void dk(){
      ll n;
      cin>>n;
      vector<ll> v(n);
      inp(v);
      sort(all(v),greater<ll>());

      for(auto it:v){
            mp[it]++;
      }

      ll ans=0;
      for(auto it:v){

              for(int i=2;i*i<=it;i++){
                  if(it%i==0){
                        if((it/i)%i==0){
                              ans+= mp[it]*mp[it/(i*i)]*mp[it/i];
                        }
                        if(it/i!=i){
                              ll x= it/i;
                              if((it/x)%x==0){
                                    ans+= mp[it]*mp[it/(x*x)]*mp[it/x];
                              }
                        }
                  }
              }
            ll x=mp[it];
            ans+= (x*(x-1)*(x-2));
            mp[it]=0;
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