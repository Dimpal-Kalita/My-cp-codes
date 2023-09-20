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





ll n,m;
vector<pair<ll,ll>>dxy={{-1,0},{1,0},{0,-1},{0,1}};
vector<string>v;
vector<vector<vector<bool>>>vis;
vector<vector<int>>mark;

void dfs(ll i, ll j,int dir){
     if(vis[i][j][dir]) return;
     vis[i][j][dir]=1;
     mark[i][j]=1;
     
     int dx=dxy[dir].F,dy=dxy[dir].S;
     if(i+dx<0 or i+dx>=n or j+dy<0 or j+dy>=m) return;
     if(v[i+dx][j+dy]=='.'){
          dfs(i+dx,j+dy,dir);
     }
     
     return;
}



void dk(){
     cin>>n>>m;
     rep(i,0,n){
          string s;
          cin>>s;
          v.pb(s);
     }
     vis.assign(n,vector<vector<bool>>(m,vector<bool>(4,0)));
     mark.assign(n,vector<int>(m,0));
     rep(i,0,n){
          rep(j,0,m){
               if(v[i][j]=='>'){
                    dfs(i,j,3);
               }
               if(v[i][j]=='<'){
                    dfs(i,j,2);
               }
               if(v[i][j]=='^'){
                    dfs(i,j,0);
               }
               if(v[i][j]=='v'){
                    dfs(i,j,1);
               }
               if(v[i][j]=='#'){
                    mark[i][j]=1;
               }
          }
     }
     debug(mark);
     queue<pair<ll,ll>>q;
     vector<vector<int>>dist(n,vector<int>(m,1e9));

     rep(i,0,n){
          rep(j,0,m){
               if(v[i][j]=='S'){
                    q.push({i,j});
                    dist[i][j]=0;
                    break;
               }
          }
     }
     
     while(!q.empty()){
          auto [x,y]=q.front();
          cerr<<x<<" "<<y<<endl;
          q.pop();
          rep(i,0,4){
               int dx=dxy[i].F,dy=dxy[i].S;
               if(x+dx<0 or x+dx>=n or y+dy<0 or y+dy>=m) continue;
               if(mark[x+dx][y+dy]) continue;
               // cerr<<x+dx<<" "<<y+dy<<" "<<dist[x+dx][y+dy]<<endl;
               if(dist[x+dx][y+dy]>dist[x][y]+1){
                    dist[x+dx][y+dy]=dist[x][y]+1;
                    q.push({x+dx,y+dy});
               }
          }
     }

     rep(i,0,n){
          rep(j,0,m){
               if(v[i][j]=='G'){
                    if(dist[i][j]==1e9) cout<<-1<<endl;
                    else cout<<dist[i][j]<<endl;
                    return;
               }
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