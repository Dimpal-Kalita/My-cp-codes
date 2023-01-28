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



ll aa, bb;
bool calc(ll s, ll x){
    ll a= (s-x)/2;
    ll ansa=0, ansb=0;
    for(ll i=0;i<30;i++){
        ll xi= (x& (1<<i));
        ll ai= (a& (1<<i));
        if(xi==0 && ai==0) continue;
        else if(xi==0 && ai!=0){
            ansa+=(1<<i);
            ansb+=(1<<i);
        }
        else if(xi!=0 && ai==0) ansa+= (1<<i);
        else {
            return 0;
        }
    }
    aa=ansa, bb=ansb;
    return 1;
}


void dk(){
     ll n;
     cin>>n;
     if(calc(2*n,n) && (aa^bb)==(aa+bb)/2){
        cout<<aa<<" "<<bb<<endl;
        return;
     }
     if(calc(2*n+1, n) && (aa^bb)==(aa+bb)/2){
        cout<<aa<<" "<<bb<<endl;
        return;
     }
     cout<<-1<<endl;
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