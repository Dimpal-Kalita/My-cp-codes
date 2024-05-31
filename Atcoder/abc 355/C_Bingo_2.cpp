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

ll n;
vector<set<ll>>row,col;
set<pll>dx,dy;

bool crow(ll x,ll y){
     return row[x].size()==0;
}

bool ccol(ll x,ll y){
     return col[y].size()==0;
}

bool diagr(ll x,ll y){
     if(x==y){
          dx.erase({x,y});
          return dx.size()==0;
     }
     return 0;
}
bool diagl(ll x,ll y){
     if(x+y==n-1){
         dy.erase({x,y});
         return dy.size()==0;
     }
     return 0;
}

void dk(){
     cin>>n;
     row.resize(n);
     col.resize(n);
     rep(i,0,n){
          rep(j,0,n){
               row[i].insert(j);
               col[i].insert(j);
          }
          dx.insert({i,i});
          dy.insert({n-i-1,i});
     }
     ll m;
     cin>>m;
     rep(i,0,m){
          ll val;
          cin>>val;
          ll x=(val-1)/n;
          ll y=(val-1)%n;
          // cout<<x<<" "<<y<<endl;
          row[x].erase(y);
          col[y].erase(x);
          if(crow(x,y) or ccol(x,y) or diagr(x,y) or diagl(x,y)){
               cout<<i+1<<endl;
               return;
          }
     }     
     cout<<-1<<endl;
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