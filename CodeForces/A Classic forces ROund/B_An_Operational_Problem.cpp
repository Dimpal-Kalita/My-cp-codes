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
     ll n;
     cin>>n;
     vector<ll> v(n);
     ll odd=0, ev=0;

     for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2==0) ev++;
        else odd++;
     }
     
     if(odd%2){
        cout<<0<<endl;
        return;
     }
     if(odd>0){
        cout<<1<<endl;
        return;
     }
     map<ll,ll> mp;
     ll ans=1e9;
     for(int i=0;i<n;i++){
        ll x=v[i];
        ll cnt=0;
        while(x%2==0){
            x/=2;
            cnt++;
        }
        mp[cnt]++;
        ans=min(ans, cnt);
     }

     cout<<((mp[ans]%2==0)?ans+1:ans)<<endl;
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