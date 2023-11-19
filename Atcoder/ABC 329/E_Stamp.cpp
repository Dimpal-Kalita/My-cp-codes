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
     string s;
     cin>>s;
     string t;
     cin>>t;

     function<bool(ll,ll)> func=[&](ll i,ll j)->bool{
          if(i==n){
               return 1;
          }
          j%=m;
          bool ans=0;
          if(s[i]==t[j])  ans|=func(i+1,j+1);
          for(int k=0;k<m;k++){
               if(k==j){
                    continue;
               }
               if(s[i]==t[k]){
                    ans|=func(i+1,k+1);
               }
          }
          return ans;
     }; 

     cout<<(func(0,0)?"Yes":"No")<<endl;
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