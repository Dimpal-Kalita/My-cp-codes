/**
 * 
 * author: Dimpal Kalita
 * date: 27/05/2023 16:48:42
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
// #define endl                " \n"
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
     string a,b;
     cin>>a>>b;
     DSU dsu(26);

     for(int i=0;i<n;i++){
          if(a[i]!=b[i]){
               dsu.join(a[i]-'a',b[i]-'a');
          }
     }
     map<ll,vector<ll>>mp;
     for(int i=0;i<26;i++){
          if(!count(all(a),i+'a') and !count(all(b),i+'a')) continue;
          mp[dsu.find(i)].pb(i);
     }

     vector<pll> ans;

     for(auto x:mp){
          if(x.S.size()==1) continue;
          for(int i=1;i<x.S.size();i++){
               ans.pb({x.S[0],x.S[i]});
          }
     }
     cout<<ans.size()<<endl;
     for(auto it:ans){
          cout<<char(it.F+'a')<<" "<<char(it.S+'a')<<endl;
     }
     cout<<endl;
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