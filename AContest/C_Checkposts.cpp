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







/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/





namespace SCCTarjan {
vector<int> val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
     int low = val[j] = ++Time, x;
     z.push_back(j);
     for (auto e : g[j])
          if (comp[e] < 0) low = min(low, val[e] ?: dfs(e, g, f));
     if (low == val[j]) {
          do {
               x = z.back();
               z.pop_back();
               comp[x] = ncomps;
               cont.push_back(x);
          } while (x != j);
          f(cont);
          cont.clear();
          ncomps++;
     }
     return val[j] = low;
}
template<class G, class F> vector<int> scc(G& g, F f) {
     int n = g.size();
     val.assign(n, 0);
     comp.assign(n, -1);
     Time = ncomps = 0;
     for (int i = 0; i < n; i++)
          if (comp[i] < 0) dfs(i, g, f);
     return comp;
}
template<class G> // convenience function w/o lambda
vector<int> scc(G& g) {
     return scc(g, [](auto& v) {});
}
} // namespace SCCTarjan
using namespace SCCTarjan;


void dk(){
      int n;
      cin>>n;
      vector<vi> adj(n+1);
      vi v(n);
      inp(v);
      int m;
      cin>>m;
      rep(i,0,m){
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
      }
      vi pos= scc(adj);
      map<ll,vector<ll>> mp;
      rep(i,1,n+1){
          mp[pos[i]].pb(v[i-1]);
      }
      ll ans=0, way=1;
      for(auto [x,y]: mp){
          ll mn= *min_element(all(y));
          ans+=mn;
          way= (way*count(all(y),mn))%md;
      }
      cout<<ans<<" "<<way<<endl;
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