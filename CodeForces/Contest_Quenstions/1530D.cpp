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




void dk(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inp(v);
    map<ll,vector<ll>> mp;
    for(ll i=0;i<n;i++){
        if(v[i]==i+1) continue;
        mp[i+1].pb(v[i]); 
    }
    vector<ll> ans(n, 0);
    vector<ll> zero;
    fr(i,n){
        if(mp[i+1].size()==0) zero.pb(i+1);
    }
    map<ll,ll> vis;
    ll x=0;
    for(ll i=0;i<n;i++){
        if(v[i]==i+1){
            if(x<zero.size()){
               ans[i]=(zero[x]);
                vis[zero[x]]++;
                x++;
            }
        }
        else{
            if(vis[v[i]]==0){
                ans[i]=v[i];
                vis[v[i]]++;
            }
        }
    }
    x=0;
    fr(i,n){
        if(ans[i]==0){
           while(vis[x])  x++;
           ans[i]=x;
        }
    }

    for(auto x: ans) cout<<x<<" ";
    cout<<endl;

      


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