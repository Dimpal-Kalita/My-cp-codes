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
     ll k,x,a;
     cin>>k>>x>>a;
     
     function<bool(ll,ll)> recur=[&](ll turn, ll cur)->bool{
          if(turn==x){
               ll got=cur*k;
               if(got>a) return 1;
               return 0;
          }
          bool flag=0;
          ll y=(a-cur)/(k-1);
          for(ll i=max(1LL,y-10);i<=max(y+10,cur);i++){
               ll w=i*(k-1)+cur;
               if(w>a){
                    flag|=recur(turn+1,cur-i);
                    break;
               }
          }
          return flag;
     };

     bool ans=0;
     for(int i=0;i<=x;i++){
          ans=recur(i,a-i);
          if(ans==0) break;
     }
     cout<<(ans?"YES":"NO")<<endl;    
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