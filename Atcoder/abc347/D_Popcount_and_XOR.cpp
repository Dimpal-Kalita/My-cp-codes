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
     ll a,b,C;
     cin>>a>>b>>C;
     ll c=__builtin_popcountll(C);
     ll val=0;
     if((a+b-c)%2==0){
          val=(a+b-c)/2;
     }else{
          cout<<-1<<endl;
          return;
     }

     if(val<0 or a-val<0 or b-val<0){
          cout<<-1<<endl;
          return;
     }
     ll arem=a-val,brem=b-val;
     ll ansa=0,ansb=0;
     ll ct=0;
     for(ll i=0;i<60;i++){
          if((C&(1LL<<i))){
               // cout<<arem<<" "<<brem<<endl;
               if(arem) ansa|=(1LL<<i),arem--;
               else if(brem) ansb|=(1LL<<i),brem--; 
          }else{
               if(val){
                    ansa|=1LL<<i;
                    ansb|=1LL<<i;
                    val--;
               }
               // cout<<val<<endl;
          }
     }
     // cout<<(ansa^ansb)<<endl;
     // cout<<__builtin_popcount(ansa)<<" "<<__builtin_popcount(ansb)<<endl;
     if((ansa^ansb)!=C or __builtin_popcountll(ansa)!=a or __builtin_popcountll(ansb)!=b){
          cout<<-1<<endl;
          return;
     }
     cout<<ansa<<" "<<ansb<<endl;
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