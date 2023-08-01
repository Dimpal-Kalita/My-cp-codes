/**
 * 
 * author: Dimpal Kalita
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;
using i128 = __int128;

ll n,m;
vl v;

bool check(i128 mid){
    i128 sum=0,val=mid*m;
    for(int i=0;i<n;i++){
        sum+=min(mid,(i128)v[i]);
    }
    return sum>=val;
}

void dk(){
     cin>>n>>m;
     v.resize(n);
     inp(v);
     ll l=0,r=1e18;
     while(l<r){
       i128 mid=l+(r-l)/2;
       if(check(mid)){
           l=mid+1;
       }
       else{
           r=mid;
       }
     }
     cout<<max(l-1,0LL)<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}