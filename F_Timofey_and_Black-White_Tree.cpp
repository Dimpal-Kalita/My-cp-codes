// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key





/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(ll t) {cerr << t;}
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





struct LCA{
    vector<vector<ll>> up;
    vector<ll> tin, tout;
    ll timer=0, distance=0;
    LCA(int n) : up(20, vector<ll>(n)), tin(n), tout(n){}
    void dfs(int v, int p, vector<vector<ll>> &adj) {
        tin[v] = ++timer;
        up[0][v] = p;
        distance++;
        for (int i = 1; i < 20; i++)
            up[i][v] = up[i-1][up[i-1][v]];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    ll lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 19; i >= 0; i--) {
            if (!is_ancestor(up[i][u], v))
                u = up[i][u];
        }
        return up[0][u];
    }
    ll dist(int u, int v) {
        int w = lca(u, v);
        return depth(u) + depth(v) - 2 * depth(w);
    }
    ll depth(int u){
        return tin[u];
    }
};




void dk(){
    int n, k;
    cin>>n>>k;
    k--;
    vector<ll> v(n-1);
    for(auto &it:v){
        cin>>it;
        it--;
    }
    debug(v);
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    LCA lca(n+1);
    lca.dfs(0, 0, adj);
    ll mn=1e18;
    for(ll i=0;i<n-1;i++){
        ll dist= lca.dist(v[i], k);
        mn= min(mn, dist);
        if(mn==1){
            cout<<1<<" ";
            continue;
        }
        for(ll j=i-1;j>=0;j--){
            dist= lca.dist(v[j], v[i]);
            mn= min(mn, dist);
            if(mn==1){
                break;   
            }
        }
        cout<<mn<<" ";
    }
    cout<<endl;

}




int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}