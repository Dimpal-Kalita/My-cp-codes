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






ll n,a,b;
vector<vl>adj;
vl vis,par;
pll tt;
array<ll,2> val;
bool dfs(ll node,ll parent){
     vis[node]=1;
     par[node]=parent;
     bool ans=0;
     for(auto x:adj[node]){
          if(vis[x]==1 and x!=parent){
               ans=1;
               val[1] = x;
               par[x] = node;
               tt={x,node};
          }else if(!vis[x]){
               ans|=dfs(x,node);
          }
     }
     vis[node]=2;
     return ans;
}

void dk(){
     cin>>n>>a>>b;
     adj.assign(n+1,{});
     vis.assign(n+1,0);
     par.assign(n+1,0);
     for(int i=0;i<n;i++){
          ll u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }

    dfs(1,0);
    ll mp = val[1];
    set<ll>cy;
    cy.insert(mp);
    val[1] = par[val[1]];
    while(val[1] != mp){
        cy.insert(val[1]);
        val[1] = par[val[1]];
    }
    debug(cy);

    ll depa = 0 , depb = 0;
    vis.assign(n+1,0);
    queue<pll>q;
    q.push({b,0});
    ll bb;
    while(!q.empty()){
          ll node=q.front().F;
          ll dep=q.front().S;
          vis[node]=1;
          q.pop();
          if(cy.count(node)){
               depb=dep;
               bb=node;
               break;
          }
          for(auto x:adj[node]){
               if(!vis[x]){
                    q.push({x,dep+1});
               }
          }
    }
     vis.assign(n+1,0);
     while(!q.empty()) q.pop();
     q.push({a,0});
     while(!q.empty()){
          ll node=q.front().F;
          ll dep=q.front().S;
          vis[node]=1;
          q.pop();
          if(node==bb){
               depa=dep;
               break;
          }
          for(auto x:adj[node]){
               if(!vis[x]){
                    q.push({x,dep+1});
               }
          }
     }
    if(depb >= depa){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
     }

}



int main()
{ 
    fast_io;
  
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}