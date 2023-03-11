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
     ll n, k;
     cin>>n>>k;
     map<char,ll> mp;
     for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        mp[ch]++;
     }
     vector<ll> dif;
     ll ans=0;
     for(char it='a';it<='z';it++){
        ll val= min(mp[it],mp[toupper(it)]);
        ans+=val;
        dif.pb(abs(mp[it]-mp[toupper(it)]));
     }
    //  cout<<ans<<endl;
     for(int i=0;i<dif.size();i++){
        ll val= min(k, dif[i]/2);
        k-=val;
        ans+=val;
     }
     cout<<ans<<endl;
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