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
#define size(x)             int((x).size());
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key








ll check(ll n){
    ll x= sqrt(n);
    ll y= cbrt(n);
    return x-y;
}

ll func(ll mid){
    ll x= mid*mid;
    ll y= exp(log(x)/3.0);
    while(y*y*y<=x) y++;
    return mid-y;
}



void dk(){
    ll x;
    cin>>x;

    ll l=0,r= 1ll<<31,ans;
    while(l<r){
        ll mid= (l+r)/2;
        if(func(mid)>=x){
            r=mid;
            ans=mid*mid;
        }
        else{
            l=mid+1;
        }
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