// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               ((long long)((x).size()));
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key




vector<pll> dir={{-1,-1},{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,1},{1,-1}};
void dk(){
     ll n, m;
     cin>>n>>m;
     vector<vector<ll>>v(n, vector<ll>(m)), dist(n, vector<ll>(m,1e18)), vis(n, vector<ll>(m,0));


     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
     }


     priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;


     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0 || i==n-1){
                pq.push({v[i][j],{i,j}});
                dist[i][j]=v[i][j];
            }
        }
     }

     while(!pq.empty()){
        ll x= pq.top().S.F;
        ll y= pq.top().S.S;
        ll n_dist= pq.top().F;
        pq.pop();
        if(vis[x][y]) continue;

        for(auto it:dir){
            ll xx=x+it.F;
            ll yy=y+it.S;
            if(xx>=0 && xx<n && yy>=0 && yy<m){
                if(n_dist+v[xx][yy]<dist[xx][yy]){
                    dist[xx][yy]=n_dist+v[xx][yy];
                    pq.push({n_dist+v[xx][yy],{xx,yy}});
                }
            }
        }
     }

     ll ans = min(v[0][0], v[n-1][m-1]);

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==m-1){
                ans= min(ans, dist[i][j]);
            }
        }
     }

     cout<<ans<<endl;


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