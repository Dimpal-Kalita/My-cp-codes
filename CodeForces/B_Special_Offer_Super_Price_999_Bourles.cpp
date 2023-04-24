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

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



void dk(){
     string s;
     ll m;
     cin>>s>>m;
     ll ans=stoll(s);
     ll n=s.length();

     ll ct=0;
     for(int i=n-1;i>=0;i--){
        if(s[i]=='9') ct++;
        else break;
     }
     
     ll i=n-1;
     ll prev=0;
     while(i>0){
        prev=(s[i]-'0')*binpow(10, n-i-1)+prev;
        ll x=prev+1;
        ll val=x;
        if(val<=m && i>ct){
            ans=stoll(s)-x;
        }
        else break;
        i--;
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