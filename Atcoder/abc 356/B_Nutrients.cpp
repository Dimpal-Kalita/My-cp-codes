/**
 * 
 * author: Dimpal Kalita
 * date: 01/06/2024 17:35:16
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
      ll n,m;
      cin>>n>>m;
      vl v(m);
      inp(v);
      vl cnt(m);
      rep(i,0,n){
          rep(j,0,m){
               ll x;
               cin>>x;
               cnt[j]+=x;
          }
      }

      rep(i,0,m){
          if(cnt[i]<v[i]){
                 cout<<"No\n";
                 return;
          }
      }
     cout<<"Yes\n";

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