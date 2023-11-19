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
     vector<set<ll>>v(n+1);
     vl count(n+1);
     rep(i,1,n+1){
          ll x;
          cin>>x;
          v[i].insert(x);
          count[i]=1;
     }

     while(m--){
          ll l,r;
          cin>>l>>r;
          if(!count[l]){
          }
          else if(!count[r]){
               swap(v[l],v[r]);
               count[r]=count[l];
               count[l]=0;
          }
          else if(v[l].size()<v[r].size()){
               for(auto i:v[l]){
                    v[r].insert(i);
               }
               count[l]=0;
               count[r]=v[r].size();
          }else{
               for(auto i:v[r]){
                    v[l].insert(i);
               }
               swap(v[l],v[r]);
               count[l]=0;
               count[r]=v[r].size();
          }    
          cout<<count[r]<<endl;
     }

}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   