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
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


typedef struct Edge{
	int u, v, w;
	bool operator<(Edge const &other){
		return w<other.w;
	}
}edge;


ll n;
vector<Edge> adj;





void dk(){
      ll m;
      cin>>n>>m;
      adj.resize(n+1);
      for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj.pb({u, v, w});
      	adj.pb({v, u, w});
      }

      sort(all(adj));

      ll cost=0;
      vector<Edge> result;
      vector<ll> tree_id(n+1);

      for(int i=1;i<=n;i++) tree_id[i]=i;

      for(auto ed:adj){
        if(tree_id[ed.u]!=tree_id[ed.v]){
            cost+=ed.w;
            result.pb(ed);

            int old_id= tree_id[ed.u], new_id=tree_id[ed.v];
            for(int i=1;i<=n;i++){
                if(tree_id[i]==old_id){
                    tree_id[i]=new_id;
                }
            }
        }
      }

      if(result.size()==n-1){
        cout<<cost<<endl;
        return;
      }

      cout<<"IMPOSSIBLE"<<endl;

}




int main()
{ 
    fast_io;
    
    //#ifndef IGNOREME
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif
    
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}