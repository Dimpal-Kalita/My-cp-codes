/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 21:49:04
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


const int N=2e5+7;
ll n,k;
vl v;

bool check(ll mid){
     ll ct=1, sum=0, mx=0;
     for(int i=0;i<n;i++){
          if(sum+v[i]>mid){
               ct++;
               sum=v[i];
          }else{
               sum+=v[i];
          }
          mx= max(mx,sum);

     }
     // mx= max(mx,sum);
     // cout<<mx<<" "<<mid<<endl;
     return ct<=k;
}


void dk(){
     cin>>n>>k;
     v.resize(n);
     inp(v);
     ll l=0, r=1e18;
     while(l<r){
          ll mid= (r-l)/2+l;
          if(check(mid)){
               r=mid;
          }else{
               l=mid+1;
          }
     }
     // check(8);
     ll ans=0,sum=0;
     for(auto x: v){
          if(sum+x>l){
               sum=x;
          }else{
               sum+=x;
          }
          ans= max(ans,sum);
     }
     cout<<ans<<endl;
     return;
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