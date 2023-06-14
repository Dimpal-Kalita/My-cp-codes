/**
 * 
 * author: Dimpal Kalita
* 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
// #define endl                " \n"
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

ll ask(ll n){
     cout<<"+ "<<n<<endl;
     ll x;
     cin>>x;
     return x;
}

void dk(){
      ll x;
      cin>>x;
      map<ll,ll> mp;
      mp[x]=0;
      ll n=1e7;
      for(int i=1;i<n;){
          if(i<1000){
               x=ask(1);
               if(mp.count(x)){
                    cout<<"! "<<i-mp[x]<<endl;
                    return;
               }
               mp[x]=i;
               i++;
          }else{
               if(i==1000){
                    cout<<"- "<<999<<endl;
                    cin>>x;
               }
               x=ask(1000);
               if(mp.count(x)){
                    cout<<"! "<<i-mp[x]<<endl;
                    return;
               }
               mp[x]=i;
               i+=1000;
          }
      }


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