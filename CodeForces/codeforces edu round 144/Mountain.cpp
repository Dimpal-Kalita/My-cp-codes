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







void dk(){
    ll n,m,q;
    cin>>n>>m>>q;
    // cout<<q;
    while(q--){
        ll x;
        cin>>x;
        ll sum=0;
        int i=0;
        vector<ll> ans;
        for(;i<n;i++){
            sum+= (i+1)*m;
            // cout<<sum<<" ";
            ans.pb(m);
            if(sum>=x) break;
        }

        for(int j=i;j>=0;j--){
            if(sum<=x) break;
            ll dif= sum-x;
            ll val= min(dif/(j+1),m);
            sum-= (j+1)*val;
            ans[j]-=val;
        }
        cout<<1<<" "<<ans.size()<<endl;
        for(auto x: ans) cout<<x<<" ";
        cout<<endl;
    }

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