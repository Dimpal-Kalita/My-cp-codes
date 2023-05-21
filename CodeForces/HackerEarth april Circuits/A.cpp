// Problem: Maze maximum
// URL: https://www.hackerearth.com/challenges/competitive/april-circuits-23/algorithm/maze-maximum-8f0fa284/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author: Dimpal Kalita
// 22-04-2023 01:00:52
 
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
    ll mx=0;
    vector<vector<ll>> v(n, vector<ll>(m));
    
    rep(i,0,n){
        rep(j,0,m) cin>>v[i][j];
    }
    
    
    for(int i=0;i<n;i++){
        ll mn=1e12;
        for(int j=0;j<m;j++){
            mn= min(mn, v[i][j]);
        }
        mx=max(mx,mn);
    }
    
    ll mx2=0;
    
    for(int i=0;i<m;i++){
        ll mn= 1e12;
        for(int j=0;j<n;j++){
            mn= min(mn, v[j][i]);
        }
        mx2= max(mx2, mn);
    }
    
    cout<<min(mx, mx2)<<endl;
 
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