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

vl vis(1e6+10,0);


void pre(){
     for(int i=2;i<=1e3;i++){
          ll sum=1+i+i*i;
          ll x=i*i;
          while(sum<=1e6){
               vis[sum]=i;
               x*=i;
               sum+=x;
          }
     }
}

void dk(){
     ll n;
     cin>>n;
     cout<<(vis[n]?"YES":"NO")<<endl;
}



int main()
{ 
    fast_io;
    pre();
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}