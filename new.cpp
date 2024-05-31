/**
 * 
 * author: Dimpal Kalita
 * date: 28/05/2024 20:12:59
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






void solve(){ 
  ll n;
  cin>>n;
  vector<ll>degree(n+1);
  for(int i=0;i<n-1;i++){
    ll x,y;
    cin>>x>>y;
    degree[x]++;
    degree[y]++;
  }
  vector<set<ll>>v(n+1);
  v[0].insert(0);
  for(ll i=1;i<=n;i++){
    for(ll j=i;j>=1;j--){
      for(auto x:v[j-1]){
        v[j].insert(x+degree[i]);
      }
    }
  }
  ll sum=0;
  for(ll i=0;i<=n;i++){
    sum+=v[i].size();
  }
  cout<<sum<<endl;
  return;
}

void dk(){
  solve();
}



int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}