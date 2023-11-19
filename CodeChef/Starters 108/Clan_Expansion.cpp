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
     inp(v);
     map<ll,vl>mp;
     for(int i=0;i<n;i++){
          mp[v[i]].push_back(i);
     }
     ll time=1e10,value=1e10;

     for(auto [x,y]:mp){
          ll tmp=max((y.front()),(n-y.back()-1));
          for(int i=1;i<y.size();i++){
               ll dif=y[i]-y[i-1]-1;
               tmp=max(tmp,(dif+1)/2);
          }
          if(time>tmp){
               time=tmp;
               value=x;
          }
     } 
     cout<<value<<" "<<time<<endl;

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