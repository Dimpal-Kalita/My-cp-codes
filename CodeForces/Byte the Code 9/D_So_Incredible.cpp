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




void dk(){
      ll n,m;
      cin>>n>>m;
      vector<ll> v(n+1);
      vector<ll> mn(n+1), pos(n+1);
      for(ll i=1;i<=n;i++){
        cin>>v[i];
        pos[v[i]]=i;
        mn[i]=n+1;
      }
      while(m--){
            ll x,y;
            cin >> x >> y;
            if(pos[x] > pos[y])swap(x,y);
            mn[pos[x]] = min(mn[pos[x]],pos[y]);
       }
       ll ans = 0, val=1;
       multiset<ll> ml;
       for(ll i=1;i<=n;i++){
          while(ml.empty() || *ml.begin() > val) ml.insert(mn[val]), val++;
          ans+= val-i;
          ml.erase(ml.find(mn[i]));
       }
       cout<<ans<<endl;
}




int main()
{ 
    fast_io;
  
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n+1);
    vector<ll> mn(n+1), pos(n+1);
    for(ll i=1;i<=n;i++){
    cin>>v[i];
    pos[v[i]]=i;
    mn[i]=n+1;
    }
    while(m--){
        ll x,y;
        cin >> x >> y;
        if(pos[x] > pos[y])swap(x,y);
        mn[pos[x]] = min(mn[pos[x]],pos[y]);
    }
    ll ans = 0, val=1;
    multiset<ll> ml;
    for(ll i=1;i<=n;i++){
          while(ml.empty() || *ml.begin() > val) ml.insert(mn[val]), val++;
          ans+= val-i;
          ml.erase(ml.find(mn[i]));
    }
    cout<<ans<<endl;

  return 0;
}