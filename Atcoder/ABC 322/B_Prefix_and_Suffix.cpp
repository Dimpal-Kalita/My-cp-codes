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
     string s,t;
     cin>>s>>t; 
     if(m<n){
          cout<<3<<endl;
          return;
     }
     bool pre=(t.substr(0,n)==s), suf=(t.substr(m-n)==s);
     if(pre and suf){
          cout<<0<<endl;
          return;
     }
     if(pre){
          cout<<1<<endl;
          return;
     }
     if(suf){
          cout<<2<<endl;
          return;
     }
     cout<<3<<endl;
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