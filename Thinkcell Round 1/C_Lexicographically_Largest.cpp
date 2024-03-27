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
     ll n;
     cin>>n;
     vl v(n);
     vector<pll> vp;
     map<ll,ll>mp;
     rep(i,0,n){
          cin>>v[i];
          v[i]+=(i+1);
          mp[v[i]]++;
     }
     while(sz(mp)){
          auto it=mp.rbegin();
          if(it->S>1){
               mp[it->F-1]+=it->S-1;
          }
          cout<<it->F<<" ";
          mp.erase(mp.find(it->F));
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