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
#define sz(x)             int((x).size());
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






vector<pii> dir={{0,-1},{-1,0},{0,1},{1,0}};
vector<int> arrowdir={0,1,2,3};

void dk(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    list<pair<pii,pii>> pq;

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4,INT_MAX)));

    dist[0][0][2]=0;
    pq.push_front({{0,2},{0,0}});
    while(!pq.empty()){
        auto it=pq.front();
        pq.pop_front();
        int x=it.S.F, y=it.S.S, d=it.F.F, arrow=it.F.S;
        if(d>dist[x][y][arrow]) continue;
        
        if(mat[x][y]=='.'){

            for(int i=0;i<4;i++){
                if(i!=arrow) continue;
                // cout<<d<<" ";
                int nx=x+dir[i].F, ny=y+dir[i].S;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

                if(dist[nx][ny][arrowdir[i]]>d){
                    dist[nx][ny][arrowdir[i]]=d;
                    pq.push_front({{d,arrow},{nx,ny}});
                }
            }
            continue;
        }

        for(int i=0;i<4;i++){
            int nx=x+dir[i].F, ny=y+dir[i].S;
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

            if(arrow==i){
                if(dist[nx][ny][arrow]>d){
                    dist[nx][ny][arrow]=d;
                    pq.push_front({{d,arrow},{nx,ny}});
                }
            }
            else{
                if(dist[nx][ny][i]>d+1){
                    dist[nx][ny][i]=d+1;
                    pq.push_back({{d+1,i},{nx,ny}});
                }
            }
        }
    }

    int mn= INT_MAX, ans=dist[n-1][m-1][2];
    if(mat[n-1][m-1]=='#'){
        for(int i=0;i<4;i++){
            if(dist[n-1][m-1][i]!=INT_MAX) ans=min(ans, dist[n-1][m-1][i]+1);
        }
    }

    cout<<(ans==INT_MAX?-1:ans)<<endl;

}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}