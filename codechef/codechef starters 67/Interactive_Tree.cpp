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









const int mx= 1e4+1;

vector<vector<ll>> adj;
map<pll,ll> mp;

ll quary(ll l, ll r){
    cout<<"? ";
    for(int i=l;i<=r;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    ll d;
    cin>>d;
    return d;
}

void dfs(ll src, ll node, ll par, ll dist){
    
    mp[{src,node}]=dist;

    for(auto i:adj[node]){
        if(i!=par){
            dfs(src, i, node, dist+1);
        }
    }

}

void calc(ll n){

    for(ll i=1;i<=n;i++){
        dfs(i,i, 0, 0);
    }
}


void dk(){
    ll n;
    cin>>n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    calc(n);
    debug(mp)
    ll ans=0;
    ll prev=-1;
    vector<ll> vis(n+1, 0);
    while(1){
        if(prev==1) {
        ll x= quary(1,1);
        vis[1]=1;
        set<ll> check;
        vector<ll> ok;
        for(int i=1;i<=n;i++){
            if(mp.count({i, x})){
                check.insert(i);
                ok.pb(i);
            }
        }
        if(check.size()==1){
            cout<<"! "<<ok[0]<<endl;
            return;
        }

        }
        else {
            ll x=0;
            for(ll i=1;i<n;i++){
                if(!vis[i]){
                }
            }




        }





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
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}