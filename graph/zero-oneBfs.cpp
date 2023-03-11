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





vector<pll> dir={{1,0},{-1,0},{0,1},{0,-1}};

void dk(){
    ll n, m;
    cin>>n>>m;

    vector<vector<ll>> mat(n, vector<ll>(m));
    vector<pll> target;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            mat[i][j]=x;
            if(x=='$') target.pb({i,j});
        }   
    }


    

    vector<vector<ll>> dist(n, vector<ll>(m, 1e18));
    vector<vector<bool>> vis(n, vector<bool>(m, false));



    priority_queue<pair<ll,pll>, vector<pair<ll,pll>>, greater<pair<ll,pll>>> pq;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=false;
            if((i==0 || i==n-1) && (mat[i][j]=='.' || mat[i][j]=='$'))  pq.push({0,{i,j}});
            if((j==0 || j==m-1) && (mat[i][j]=='.' || mat[i][j]=='$'))  pq.push({0,{i,j}});
            if((i==0 || i==n-1) && mat[i][j]=='#') pq.push({1,{i,j}});
            if((j==0 || j==m-1) && mat[i][j]=='#') pq.push({1,{i,j}});
        }
    }


    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        ll d=it.F;
        ll x=it.S.F;
        ll y=it.S.S;
        dist[x][y]=d;
        for(auto it:dir){
            ll dx=it.F;
            ll dy=it.S;
            if(x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m){
                ll cost=0;
                if(mat[x+dx][y+dy]=='*') continue;
                if(mat[x+dx][y+dy]=='#') cost=1;
                if(dist[x+dx][y+dy]>d+cost){
                    dist[x+dx][y+dy]=d+cost;
                    pq.push({d+cost,{x+dx,y+dy}});
                }
            }
        }
    }

    // debug(dist);

    vector<vector<ll>> dist1(n, vector<ll>(m, 1e18)), dist2(n, vector<ll>(m, 1e18));
    
    priority_queue<pair<ll,pll>, vector<pair<ll,pll>>, greater<pair<ll,pll>>> pq1, pq2;

    pq1.push({0,{target[0].F, target[0].S}});
    pq2.push({0,{target[1].F, target[1].S}});

    while(!pq1.empty()){
        auto it=pq1.top();
        pq1.pop();
        ll d=it.F;
        ll x=it.S.F;
        ll y=it.S.S;

        // if(d>=dist1[x][y]) continue;
        dist1[x][y]=d;

        for(auto it:dir){
            ll dx=it.F;
            ll dy=it.S;
            if(x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m){
                ll cost=0;
                if(mat[x+dx][y+dy]=='*') continue;
                if(mat[x+dx][y+dy]=='#') cost=1;
                if(dist1[x+dx][y+dy]>d+cost){
                    dist1[x+dx][y+dy]=d+cost;
                    pq1.push({d+cost,{x+dx,y+dy}});
                }
            }
        }
    }

    while(!pq2.empty()){
        auto it=pq2.top();
        pq2.pop();
        ll d=it.F;
        ll x=it.S.F;
        ll y=it.S.S;

        // if(d>=dist2[x][y]) continue;
        dist2[x][y]=d;

        for(auto it:dir){
            ll dx=it.F;
            ll dy=it.S;
            if(x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m){
                ll cost=0;
                if(mat[x+dx][y+dy]=='*') continue;
                if(mat[x+dx][y+dy]=='#') cost=1;
                if(dist2[x+dx][y+dy]>d+cost){
                    dist2[x+dx][y+dy]=d+cost;
                    pq2.push({d+cost,{x+dx,y+dy}});
                }
            }
        }
    }

    ll ans=1e18;    
    for(int it=0;it<n;it++){
        for(int itr=0;itr<m;itr++){
            if(mat[it][itr]=='*') continue;
            ll distance=dist[it][itr]+dist1[it][itr]+dist2[it][itr];
            if(mat[it][itr]=='#') distance-=2;
            ans= min(ans, distance);
        }
    }


    cout<<ans<<endl;

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