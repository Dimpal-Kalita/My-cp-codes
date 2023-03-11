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
      ll n;
      cin>>n;
      vector<ll> p(n), q(n);
      inp(p);
      inp(q);

      map<ll,ll> mp1, mp2;
      for(int i=0;i<n;i++){
        mp1[p[i]]=i+1;
      }
      for(int i=0;i<n;i++){
        mp2[q[i]]=i+1;
     }
     ll ans=0; ll x=min(mp1[1], mp2[1]), y=max(mp1[1], mp2[1]);
     ll x1= mp1[1];
     ll y1= mp2[1];
     if(x1>y1) swap(x1,y1);

     ans+= (x1*(x1-1))/2 + ((n-y1)*(n-y1+1))/2+ ((y1-x1)*(y1-x1-1))/2;
     map<pair<ll,ll> ,ll> pp;
     
     //  pp[{x,y}]++;
      cerr<<x<<" "<<y;
     for(int i=1;i<=n;i++){
        x= min(mp1[i],min(mp2[i], x));
        y= max(mp2[i],max(y, mp1[i]));

        if(pp.count({x,y})) continue;
        
        pp[{x,y}]++;
        // cerr<<x<<" "<<y<<endl;
        ans++;
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