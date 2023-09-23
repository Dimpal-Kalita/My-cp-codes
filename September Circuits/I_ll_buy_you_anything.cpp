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
     ll n;
     cin>>n;
     map<ll,vector<ll>>mp;
     vl v(n);
     inp(v);
     DSU dsu(n+1);
     for(int j=0;j<n;j++){
          ll x=v[j];
          for(ll i=1;i*i<=x;i++){
               if(x%i==0){
                    mp[i].pb(j);
                    if(i*i!=x) mp[x/i].pb(j);
               }
          }
     }
     ll ans=0;
     for(auto it=mp.rbegin();it!=mp.rend();it++){
          vector<ll>fac=it->S;
          if(fac.size()>1){
               for(int i=1;i<fac.size();i++){
                    if(dsu.same(fac[i],fac[i-1])) continue;
                    dsu.join(fac[i],fac[i-1]);
                    ans+=it->F;
               }
          }
     }
     cout<<ans<<endl;
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