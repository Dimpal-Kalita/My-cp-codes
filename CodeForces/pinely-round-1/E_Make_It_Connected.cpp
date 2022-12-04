// 2112048
// Dimpal Kalita
// CSE sec A

#include<bits/stdc++.h>


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
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
    ll sz(ll a){
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



void dk(){
     ll n;
     cin>>n;
     string s[n];
     fr(i,n) cin>>s[i];
     vector<vector<ll>> adj(n);
     DSU dsu;
     dsu.init(n);

     fr(i,n){
          fr1(j,i+1, n){
               if(s[i][j]=='1') dsu.unite(i, j);
          }
     }

     ll mx=1e9;
     ll par=0;

     ll comp= dsu.total_components;
     for(ll i=0;i<n;i++){
          if(dsu.sz(i)<=mx){
               mx=dsu.sz(i);
               par=dsu.get(i);
          }
     }

     vector<ll> ans;
     for(ll i=0;i<n;i++){
          if(dsu.get(i)==par) ans.pb(i);
     }
     if(ans.size()==n){
          cout<<0<<endl;
          return;
     }

     if(comp==2){
     cout<<ans.size()<<endl;
     for(auto i:ans) cout<<i+1<<" ";
     cout<<endl;
     }
     else{
          cout<<2<<endl;
          
     }
}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}