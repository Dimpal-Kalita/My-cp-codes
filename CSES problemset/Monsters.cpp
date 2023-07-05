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





void dk(){
     int n,m;
     cin>>n>>m;
     vector<string>grid(n);
     rep(i,0,n) cin>>grid[i]; 

     queue<pair<int,int>>q;
     vector<vector<int>>dist(n,vector<int>(m,1e7)),vis(n,vector<int>(m,0));
     rep(i,0,n){
         rep(j,0,m){
             if(grid[i][j]=='M'){
                 q.push({i,j});
                 dist[i][j]=0;
                 vis[i][j]=1;
             }
         }
     }
     vector<pair<int,int>>dxy={{0,1},{0,-1},{1,0},{-1,0}};
     while(!q.empty()){
         auto [x,y]=q.front();
         q.pop();
         for(auto [dx,dy]:dxy){
             int nx=x+dx,ny=y+dy;
             if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && !vis[nx][ny]){
                 vis[nx][ny]=1;
                 dist[nx][ny]=dist[x][y]+1;
                 q.push({nx,ny});
             }
         }
     }

     queue<pair<int,int>>q1;
     vector<vector<int>>dist1(n,vector<int>(m,1e7)),vis1(n,vector<int>(m,0));
     pair<int,int> end={-1,-1},start={-1,-1};
     rep(i,0,n){
          rep(j,0,m){
               if(grid[i][j]=='A'){
                    start={i,j};
                    q1.push({i,j});
                    dist1[i][j]=0;
                    vis1[i][j]=1;
                    break;
               }
          }
     }

     while(!q1.empty()){
           auto [x,y]=q1.front();
           q1.pop();
           if(x==0 || x==n-1 || y==0 || y==m-1){
                end={x,y};
                break;
           }
           for(auto [dx,dy]:dxy){
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]=='#'|| dist[nx][ny]<=dist1[x][y]+1 || vis1[nx][ny]) continue;
                vis1[nx][ny]=1;
                dist1[nx][ny]=dist1[x][y]+1;
                q1.push({nx,ny});
           }

     }

     if(end.F==-1){
          cout<<"NO"<<endl;
          return;
     }
     cout<<"YES"<<endl;
     cout<<dist1[end.F][end.S]<<endl;
     string ans="";
     int x=end.F,y=end.S;
     while(x!=start.F || y!=start.S){
          for(auto [dx,dy]:dxy){
               int nx=x+dx,ny=y+dy;
               if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]=='#'|| dist1[nx][ny]!=dist1[x][y]-1) continue;
               if(dx==1) ans+='U';
               else if(dx==-1) ans+='D';
               else if(dy==1) ans+='L';
               else ans+='R';
               x=nx,y=ny;
               break;
          }
     }
     reverse(all(ans));
     cout<<ans<<endl;
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