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





void dfs(ll node, ll par, vector<vector<pll>> &adj,vector<ll>&val, ll x){


    for(auto it:adj[node]){
        if(it.F!=par){
            val[it.F]=val[node]^it.S;
            dfs(it.F,node,adj,val,x);
        }
    }

}



void dk(){
     ll n;
     cin>>n;
     vector<vector<pll>> adj(n+1);
     vector<ll> val(n+1);
     map<ll,vector<pll>> mp;

     for(int i=0;i<n-1;i++){
         ll u,v,w;
         cin>>u>>v>>w;
         adj[u].pb({v,w});
         adj[v].pb({u,w});
         if(u>v) swap(u,v);
         mp[w].pb({u,v});
     }

     dfs(1,0,adj,val,0);
     debug(val);

     for(auto it:mp){
        if(it.S.size()>1){
            // cout<<"YES"<<endl;
            cout<<it.S[0].F<<" "<<it.S[0].S<<" "<<it.S[1].F<<" "<<it.S[1].S<<endl;
            return;
        }
     }



     if(n<1025){

        map<ll,pll> mp1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ll x= val[i]^val[j];
                if(mp1.count(x)){
                    cout<<mp1[x].F<<" "<<mp1[x].S<<" "<<i<<" "<<j<<endl;
                    return;
                }
                else{
                    mp1[x]={i,j};
                }
            }
        }

        cout<<-1<<endl;
        return;
     }

     int N=1025;
    map<ll,pll> mp1;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            ll x= val[i]^val[j];
            if(mp1.count(x)){
                cout<<mp1[x].F<<" "<<mp1[x].S<<" "<<i<<" "<<j<<endl;
                return;
            }
            else{
                mp1[x]={i,j};
            }
        }
    }
 

     
     


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