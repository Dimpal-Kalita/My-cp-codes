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


struct BIT{
    vector<ll> bit;
    ll n;
    BIT(ll n){
        this->n=n;
        bit.assign(n+1,0);
    }
    ll sum(ll r){
        ll ret=0;
        for(;r;r-=r&-r) ret+=bit[r];
        return ret;
    }
    ll sum(ll l, ll r){
        return sum(r)-sum(l-1);
    }
    void add(ll idx, ll delta){
        for(;idx<=n;idx+=idx&-idx) bit[idx]+=delta;
    }
};


void dk(){
      ll n,q,k;
      cin>>n>>q>>k;
      vector<ll> v(n+1);
      while(q--){
         ll c, l, r;
         cin>>c>>l>>r;
         if(c==1){
           v[l]+=r;
         }
         else{
 
          ll sum= k;
          ll val= (r-l+1)*700;
          for(int i=l;i<=r;i++){
            sum+=v[i];
          }
          if(sum>=val){
            cout<<"YES"<<endl;
          }
          else{
            cout<<"NO"<<endl;
          }
         }
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