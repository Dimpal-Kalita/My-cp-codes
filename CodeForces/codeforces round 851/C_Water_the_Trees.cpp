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









bool checkeven(ll x,vector<ll> v){
    ll one=(x+1)/2, two=x/2;
    for(auto &it:v){
        if(it%2==0){
            it++;
            one--;
        }
    }
    if(one<0) return 0;
    ll mx= *max_element(all(v));
    ll sum=0;
    for(auto it:v){
        sum+=(mx-it);
    }
    return (one+2*two)>=sum;
}
bool checkodd(ll x, vector<ll> v){
    ll one=(x+1)/2, two=x/2;
    for(auto &it:v){
        if(it%2==1){
            it++;
            one--;
        }
    }
    if(one<0) return 0;
    ll mx= *max_element(all(v));
    ll sum=0;
    for(auto it:v){
        sum+=(mx-it);
    }
    return (one+2*two)>=sum;
}

void dk(){
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);
     ll l=0, r=1e18;
     while(l<r){
         ll mid=(l+r)/2;
         if(checkeven(mid,v) || checkodd(mid,v)) r=mid;
         else l=mid+1;
     }
     cout<<r<<endl;
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