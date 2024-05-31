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


#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



struct DSU {
     vector<int> s;
     DSU(int n): s(n, -1) {}
     int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
     bool join(int a, int b) {
          a = find(a), b = find(b);
          if (a == b) return false;
          if (s[a] > s[b]) swap(a, b);
          s[a] += s[b], s[b] = a;
          return true;
     }
     int size(int i) { return -s[find(i)]; }
     bool same(int a, int b) { return find(a) == find(b); }
};

void dk(){
      ll n,m;
      cin>>n>>m;
      vector<array<ll,3>> v(m);
      rep(i,0,m){
          ll a,b,c;
          cin>>a>>b>>c;
          v[i]={a,b,c};
      }
      ll q;
      cin>>q;
      vector<pll> qv(q);
      rep(i,0,q){
          ll a,b;
          cin>>a>>b;
          qv[i]={a,b};
      }
      vl ans(q,-1);
      // for checking if we can find a road without 0
      for(ll i=0;i<30;i++){
          DSU dsu(n+1);
          for(auto x: v){
              if(x[2]&(1<<i)){
                  dsu.join(x[0],x[1]);
              }
          }
          for(ll j=0;j<q;j++){
              if(ans[j]!=-1) continue;
              if(dsu.same(qv[j].F,qv[j].S)){
                  ans[j]=0;
              }
          }
      }
      // 0 is in every road, we will check if we can find a road without 1... means atleast two bits are on 0th and ith or the road consist of even numbers
      for(ll i=1;i<30;i++){
          DSU dsu(n+1);
          for(auto x: v){
              if(x[2]%2){
               if(x[2]&(1<<i)){
                  dsu.join(x[0],x[1]);
               }
              }else{
               dsu.join(x[0],x[1]);
              }
          }
          for(ll j=0;j<q;j++){
               if(ans[j]!=-1) continue;
              if(dsu.same(qv[j].F,qv[j].S)){
                  ans[j]=1;
              }
          }
      }
      for(auto x:ans){
          cout<<(x==-1?2:x)<<endl;
      }
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   