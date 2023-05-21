/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 13:53:45
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




const int N=2e5+7;

vl adj[N] , dist1(N,0),dist2(N,0), par1(N,0), par2(N);

ll sz[N], maxsz[N], maxdist[N];
ll n;

void dfs1(int u, int p) {
    sz[u] = 1;
    maxsz[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        maxsz[u] = max(maxsz[u], sz[v]);
    }
    maxsz[u] = max(maxsz[u], n - sz[u]);
}

void dfs2(ll u, ll p, ll maxup) {
    maxdist[u] = max(maxsz[u], maxup);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, max(maxup + sz[u] - sz[v], maxsz[v] + n - sz[v]));
    }
}


void dk(){
     cin>>n;
     rep(i,0,n-1){
          ll x;
          cin>>x;
          adj[i+2].pb(x);
          adj[x].pb(i+2);
     }
     dfs1(1, 0);
     dfs2(1, 0, 0);
     int minmaxdist = *min_element(maxdist + 1, maxdist + n + 1);

     for (int u = 1; u <= n; u++) {
     //    cout<<maxdist[u]<<" ";
        if (maxdist[u] == minmaxdist) {
            cout << u << " ";
        }
     }
    cout << endl;
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