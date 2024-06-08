#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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
     ll n,m,k;
     cin>>n>>m>>k;
     map<ll,pll>mp;
     vector<ll>ans(k,1);
     rep(i,0,k){
          ll x,y;
          cin>>x>>y;
          if(!mp.count(x)){
               mp[x]={y,i};
          }else{
               if(mp[x].F<y){
                    ans[i]=0;
               }else{
                    ans[mp[x].S]=0;
                    mp[x]={y,i};
               }
          }
     }

     ll total=0;
     ll lastrow=n,lastcol=m;
     for(auto it=mp.rbegin();it!=mp.rend();it++){
          ll x=it->F,y=it->S.F,ind=it->S.S;
          if(lastcol<y){
               total+=(lastrow-x)*lastcol;
               ans[ind]=0; 
          }else{
               total+=(lastrow-x)*lastcol;
               lastcol=y-1;
               ans[ind]=1;
          }
          lastrow=x;
     }
     total+=lastrow*lastcol;
     cout<<total<<endl;
     for(auto i:ans) cout<<i<<" ";
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