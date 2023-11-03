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


void dk(){
      ll n,m;
      cin>>n>>m;
      vl v(n);
      inp(v);

      auto check=[&](ll x)->bool{
          if(*max_element(all(v))>x) return 0;
          ll ct=1,s=0;
          for(auto i:v){
               ll temp=(s|i);
               if(temp>x){
                    ct++;
                    s=0;
               }
               s|=i;
          }
          return ct<=m;
      };
      ll l=0,r=1e14;
      while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
              r=mid;
          }
          else{
              l=mid+1;
          }
      }
      cout<<l<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   