/**
 * 
 * author: Dimpal Kalita
 * date: 01/06/2023 13:52:17
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
#define USACO               freopen("longpath.in", "r", stdin); freopen("longpath.out", "w", stdout);


using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;






void dk(){
     ll n,k;
     cin>>n>>k;
     ll ans=0;
     for(int i=1;i<=n;i++){
          ans= (ans+k)%i;
     }
     cout<<ans+1<<endl;
}



int main()
{ 
    fast_io;
//     USACO;
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}