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
     string s;
     cin>>s;
     map<pll,ll>mp;
     ll l=-1,r=-1,mn=1e9;
     ll x=0,y=0;
     mp[{0,0}]=0;
     for(int i=0;i<n;i++){
          if(s[i]=='L') x--;
          if(s[i]=='R') x++;
          if(s[i]=='U') y++;
          if(s[i]=='D') y--;
          if(mp.find({x,y})!=mp.end()){
               if(i-mp[{x,y}]<mn){
                    mn=i-mp[{x,y}];
                    l=mp[{x,y}]+1;
                    r=i+1;
               }
          }
          mp[{x,y}]=i+1;
     }
     if(l==-1) cout<<-1<<endl;
     else cout<<l<<" "<<r<<endl;
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