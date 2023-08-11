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


ll n,k;
vl v;
bool check(ll mid){
     
     if(*max_element(all(v))>=mid) return 1;
     for(int i=0;i<n-1;i++){
          ll ct=0,req=mid;
          ct+=req-v[i];
          req--;
          bool possible=0;
          for(int j=i+1;j<n;j++){
               if(v[j]>=req){
                    possible=1;
                    break;    
               }
               ct+=req-v[j];
               req--;
          }
          if(possible && ct<=k){
               return 1;
          }
     }
     return 0;
}
void dk(){
     cin>>n>>k;
     v.resize(n); 
     inp(v);
     ll l=0,r=1e10,ans=0;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
               l=mid+1;
               ans=mid;
          }
          else{
               r=mid;
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
    dk();
   }
  return 0;
}