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






const int N=201, M=201;
ll n, m;

typedef pair<pll,ll>dpll;

map<pll,pll>mp;
vector<vector<ll>>v(N,vector<ll>(M,0));

pll recur(ll i, ll j,ll power){
    if(j>=m || i>=n) return {0,0};

    // if(mp.count({i, j})){
    //     if(power > mp[{i,j}].F)  return mp[{i,j}]={mp[{i,j}].F+power-mp[{i,j}].S, power};
    //     else return mp[{i,j}];
    // }

    // if(power<v[i][j]) return {0,0};

    // cout<<power<<" ";
    ll ps=power, ans=1;
    for(int ind=i+1;ind<n;ind++){
        if(ps>v[ind][j]){
            ans= max(ans,recur(ind,j, ps).F);
            break;
        }
    }


    ps=power+v[i][j];
    for(int ind=j+1;ind<m;ind++){
        if(ps<v[i][ind]){
            ans= max(ans,recur(i,ind,ps).F);
            break;
        }
    }

    return mp[{i,j}]={ans, power};
}




void dk(){

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>v[i][j];
    }
    ll ans=0;
    recur(0,0,0);
    debug(mp);
    for(auto it:mp){
        ans= max(ans, it.S.F);
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