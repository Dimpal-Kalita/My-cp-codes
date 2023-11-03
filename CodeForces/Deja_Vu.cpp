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
     ll n,q;
     cin>>n>>q;
     vl v(n);
     inp(v);
     vl vis(31,0);
     vl query;
     for(int i=0;i<q;i++){
         ll x;
         cin>>x;
         if(!vis[x]) query.pb(x);
         vis[x]=1;
     }

     for(auto &i:v){
          for(auto x:query){
              if(i%(1<<x)==0){
                  i+=(1<<(x-1));
              }
          }
     }
     for(auto x:v){
         cout<<x<<" ";
     }
     cout<<endl;

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