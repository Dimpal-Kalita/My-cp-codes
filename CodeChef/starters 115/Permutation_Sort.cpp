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




void dk(){
     ll n;
     cin>>n;
     vl v(n);
     vector<vl>adj(n+1);
     vl ind(n+1);
     rep(i,0,n){
          cin>>v[i];
          adj[i+1].pb(v[i]);
          ind[v[i]]=i+1;
     }
     set<vector<ll>>cycle;
     vector<ll>vis(n+1,0),par(n+1,0);
     function<void(ll,ll)>dfs=[&](ll u,ll p)->void{
          vis[u]=1;
          par[u]=p;
          for(auto x:adj[u]){
               if(vis[x]==0){
                    dfs(x,u);
               }else if(vis[x]==1){
                    vl temp;
                    for(ll i=u;i!=x;i=par[i]){
                         temp.pb(i);
                    }
                    temp.pb(x);
                    if(temp.size()>1) cycle.insert(temp);
               }
          }
          vis[u]=2;
     };
     for(int i=1;i<=n;i++){
          if(vis[i]==0) dfs(i,i);
     }
     // debug(cycle);
     while(cycle.size()>0){
          vector<ll>ans;
          debug(cycle);
          auto ttt=cycle;
          // debug(ttt);
          for(auto temp:ttt){
               cycle.erase(cycle.find(temp));
               ll last=0,ct=0;
               for(int i=0;i<temp.size();i++){
                    if(vis[i]) continue;
                    ans.pb(ind[temp[i-1]]);
                    ans.pb(ind[temp[i]]);
                    ind[temp[i-1]]=ind[temp[i]];
               }
          }
          req.pb(ans);
     }
     cout<<req.size()<<endl;
     for(auto x:req){
          cout<<x.size()<<" ";
          for(auto y:x) cout<<y<<" ";
          cout<<endl;
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