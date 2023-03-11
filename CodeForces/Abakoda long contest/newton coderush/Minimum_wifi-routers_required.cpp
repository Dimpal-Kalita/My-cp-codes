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

ll n, k;
vector<ll> v;


bool check(ll r){
    ll cur=v[0]+2*r, count=1;
    
    for(int i=1;i<n;i++){
        if(v[i]<=cur) continue;
        count++;
        cur=v[i]+2*r;
    }
    return count<=k;
}


void dk(){
      cin>>n;
      v.resize(n);
      inp(v);
      cin>>k;
      sort(all(v));
      ll l=0, r=1e6;
      ll ans=0;
      while(l<r){
        ll mid=(l+r)/2;

        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
      }
      cout<<r<<endl;
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