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
     ll n;
     cin>>n;
     vl a(n);
     map<ll,ll>mp,mpb;
     for(auto &i:a){
          cin>>i;
     }
     vl b(n);
     for(auto &i:b){
          cin>>i;
          mpb[i]++;
     }
     ll m;
     cin>>m;
     vl d(m);
     for(auto &i:d){
          cin>>i;
          mp[i]++;
     }

     if(mpb[d.back()]==0){
          cout<<"NO"<<endl;
          return;
     }

     rep(i,0,n){
          if(a[i]==b[i])  continue;
          if(mp[b[i]]==0){
               cout<<"NO"<<endl;
               return;
          }
          mp[b[i]]--;
     }
     
     cout<<"YES"<<endl;
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