/**
 * 
 * author: Dimpal Kalita
* 
 */

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
     string s;
     cin>>s;
     ll n=s.length();
     map<char,ll> mp,pos;
     for(int i=0;i<n;i++){
          mp[s[i]]++;
          pos[s[i]]=i;

     } 
     ll mx=0;
     vector<pair<ll,char>>vp;
     for(auto [x,y]:mp){
          mx=max(mx,y);
     }
     for(auto  [x,y]:mp){
          if(y==mx){
               vp.pb({pos[x],x});
          }
     }
     sort(all(vp));

     for(auto it:vp){
          cout<<it.S;
     }
     cout<<endl;


}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}