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
     ll n,m,k;
     cin>>n>>m>>k;
     DSU dsu(n+1);

     rep(i,0,m){
          vector<ll>v;
          rep(j,0,k){
               ll x;
               cin>>x;
               v.pb(x);
          }

          for(auto it:v){
               for(auto it2:v){
                    dsu.join(it,it2);
               }
          }
     }

     ll sz;
     cin>>sz;
     map<ll,ll> quar, parent;
     rep(i,0,sz){
          ll x;
          cin>>x;
          quar[x]++;
          parent[dsu.find(x)]++;
     }

     vl ans;
     rep(i,1,n+1){
          if(quar.count(i)) continue;

          if(parent.count(dsu.find(i))) ans.pb(i);
     }
     
     cout<<ans.size()<<endl;

     for(auto it:ans){
          cout<<it<<" ";
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