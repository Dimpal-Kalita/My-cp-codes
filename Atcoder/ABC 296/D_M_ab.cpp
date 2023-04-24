// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               ((long long)((x).size()));
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
     ll n, m;
     cin>>n>>m;
     ll ans=1e18;
     ll sz= sqrt(m)+1;

     for(int i=1;i<=min(n,sz);i++){

        ll a=i;
        ll b= (m-1)/a+1;
        ll x=a*b;
        // cout<<x<<" ";
        if(b<=n) ans= min(ans, x);

        if(m/i>=1 && m/i<=n){ 
            ll a=m/i;
            ll b= (m-1)/a+1;
            if(b>n) continue;
            ll x=a*b;
            // cout<<x<<endl;
            ans= min(ans, x);
        }


     }

     if(ans==1e18){
        cout<<-1<<endl;
        return;
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