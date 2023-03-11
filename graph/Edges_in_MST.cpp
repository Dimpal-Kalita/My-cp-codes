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



struct DSU{
    vector<ll> parent;
    vector<ll> size;
    ll total_components;

    void init(ll n){
        parent.resize(n);
        size.resize(n);
        for(ll i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        total_components=n;
    }

    ll get(ll a){
        if(a==parent[a]) return a;
        return parent[a]=get(parent[a]);
    }
    ll getsize(ll a){
        return size[get(a)];
    }

    void unite(ll a,ll b){
        a=get(a);
        b=get(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
            total_components--;
        }
    }
};



struct Edge{
    int u, v, w;
    bool operator<(const Edge &other) const{
        return w<other.w;
    }
};

typedef struct ppll{
    int u, v, w;
    bool operator<(const ppll &other) const{
        if(u==other.u){
            if(v==other.v){
                return w<other.w;
            }
            return v<other.v;
        }
        return u<other.u;
    }
} ppll;


void dk(){
      int n,m;
      cin>>n>>m;
      
      vector<Edge>adj;

      map<ppll,int> mp;

      for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj.pb({u, v, w});
      }
      vector<Edge> temp=adj;
      sort(all(adj));
      vector<Edge>result;
      DSU dsu;
      dsu.init(n+1);
      for(auto it:adj){
        mp[{it.u, it.v, it.w}]++;
        if(dsu.get(it.u)!=dsu.get(it.v)){
            dsu.unite(it.u, it.v);
            result.pb(it);
        }
      }

      for(auto it:temp){

        if(binary_search(all(result), it)){
            cout<<mp[{it.u, it.v, it.w}]<<" ";            
            if(mp[{it.u, it.v, it.w}]==1){
                cout<<"any"<<endl;
            }else{
                cout<<"at least one"<<endl;
            }

        }
        else{
            cout<<"none"<<endl;
        }
      }


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