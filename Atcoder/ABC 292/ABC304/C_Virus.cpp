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
      ll n, d;
      cin>>n>>d;
      vector<pll> v;
      rep(i,0,n){
          ll x,y;
          cin>>x>>y;
          v.pb({x,y});
      }
      DSU dsu(n);

      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
               ll dist= (v[i].F-v[j].F)*(v[i].F-v[j].F) + (v[i].S-v[j].S)*(v[i].S-v[j].S);
               if(dist<=d*d){
                    dsu.join(i,j);
               }
          }
      }

      for(int i=0;i<n;i++){
          if(dsu.same(0,i)){
               cout<<"Yes"<<endl;
          }
          else{
               cout<<"No"<<endl;
          }
      }
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