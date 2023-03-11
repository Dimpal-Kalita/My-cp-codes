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


ll n, s;
vector<ll> v;


ll recur(ll i,ll val, map<pll,ll> &mp){

    if(i>=n) return 0;
    if(i==n-1) return val*v[n-1];
    if(mp.count({i, val})) return mp[{i, val}];

    ll mn=min(s, v[i]-s);
    ll mx=max(s, v[i]-s);
    if(s>v[i]) mn=0, mx=v[i];
    
    ll left= recur(i+1, mx, mp) + val*mn;
    ll right= recur(i+1, mn,mp) + val*mx;
    
    return mp[{i, val}]= min(left, right);
}



void dk(){
    cin>>n>>s;
    v.resize(n);
    map<pll, ll> mp;
    inp(v);
    cout<<recur(1, v[0], mp)<<endl;
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