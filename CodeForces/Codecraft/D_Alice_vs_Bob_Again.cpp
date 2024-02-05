#include<bits/stdc++.h>
using namespace std;

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
const ll md=1e9+7;

void dk(){
     ll n;
     cin>>n;
     map<ll,ll>mp;
     string s;
     cin>>s;
     rep(i,0,n){
          mp[s[i]-'a']++;
     }
     vector<pll>dp(27);

     for(int ind=25;ind>=0;ind--){
          ll mx=-mp[ind];
          pll ans={mp[ind],0};
          for(int i=ind+1;i<26;i++){
               pll p=dp[i];
               ll x=p.S+mp[ind],y=p.F;
               if(y-x>mx){
                    mx=y-x;
                    ans={x,y};
               }
          }
     }
     pll ans=dp[0];
     // cout<<ans.F<<" "<<ans.S<<endl;
     if(ans.F>ans.S) cout<<"Alice"<<endl;
     else if(ans.F<ans.S) cout<<"Bob"<<endl;
     else cout<<"Draw"<<endl;
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