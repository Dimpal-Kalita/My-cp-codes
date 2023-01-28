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


ll f(ll x){
    if(x==1) return 0;
    if(x%2==0) return f(x/2)+1;
    return f(x/2);
}

ll g(ll x){
    if(x==1) return 1;
    if(x%2==0) return 2*g(x/2)+1;
    return 2*g(x/2);
}




void dk(){
    ll l, r;
    cin>>l>>r;
    ll x= log2(r);
    x= 1ll<<x;
    // cout<<x<<" ";
    if(x>=l && x<=r){
        cout<<f(x)+g(x)<<endl;
        return;
    }

    ll mx=0;
    for(ll i=l;i<=l+20;i++){
       mx= max(mx, f(i)+g(i));
    }
    cout<<mx<<endl;
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