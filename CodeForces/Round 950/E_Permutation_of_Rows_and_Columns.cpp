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
     ll n,m;
     cin>>n>>m;
     vector<vl>a(n,vl(m));
     map<ll,ll>x,y;
     rep(i,0,n){
          rep(j,0,m){
               cin>>a[i][j];
               x[a[i][j]]=i;
               y[a[i][j]]=j;
          }
     } 
     vector<vl>b(n,vl(m));
     bool flag=1;
     rep(i,0,n){
          rep(j,0,m){
               cin>>b[i][j];
               if(!x.count(b[i][j]) or x[b[i][j]]!=x[b[i][0]] or y[b[i][j]]!=y[b[0][j]]){
                    flag=0;
               }
          }
     }
     cout<<(flag?"YES":"NO")<<endl;
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