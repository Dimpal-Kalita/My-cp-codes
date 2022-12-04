// 2112048
// Dimpal Kalita

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

ll n , a , b;
vector<vector<pll>> adj;
vector<ll> aa , bb;

void dfs1(ll node , ll parent , ll x){
    for(auto it:adj[node]){
        if(it.first != parent && it.first!=b){
            x^=it.second;
            aa[it.first] = x;
            dfs1(it.first , node , x);
            x^=it.second;
        }
    }
}

void dfs2(ll node , ll parent , ll x){
    for(auto it:adj[node]){
        if(it.first != parent){
            x^=it.second;
            bb[it.first] = x;
            dfs2(it.first , node , x);
            x^=it.second;
        }
    }
}



void dk()
{
    cin >> n >> a >> b;
    aa.clear(); bb.clear();
    aa.resize(n+1); bb.resize(n+1);
    adj.clear();
    adj.resize(n+1);
    for(int i = 0 ; i < n-1 ; i ++){
        ll u , v , w; cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
    dfs1(a , 0 , 0);
    dfs2(b , 0 , 0);
    map<ll,ll> mpp;
    for(int i = 1 ; i <= n ;i ++){
        mpp[aa[i]]++;
    }
    for(int i = 1 ; i <= n ; i ++){
        if(i != b){
            ll tmp = mpp[bb[i]];
            if(aa[b] == bb[i]){
                tmp--;
            }
            if(tmp > 0){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;

   

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