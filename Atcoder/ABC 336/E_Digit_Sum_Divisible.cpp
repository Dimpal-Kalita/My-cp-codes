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




#define ll long long
string s;
ll dp[20][200][200][2];
ll recur(ll ind,ll sum,ll div,ll fix,ll flag){
     if(ind==sz(s)){
          if(div==0 and sum==0) return 1;
          return 0;
     }
     if(dp[ind][sum][div][flag]!=-1) return dp[ind][sum][div][flag];
     ll ans=0;
     ll l=0,r=9;
     if(flag) r=s[ind]-'0';
     for(int i=l;i<=r;i++){
          if(sum>=i) ans+=recur(ind+1,sum-i,(div*10+i)%fix,fix,flag&(i==r));
     }
     return dp[ind][sum][div][flag]=ans;
}


void dk(){
     ll n;
     cin>>n;
     s=to_string(n);
     ll ans=0;
     for(int i=1;i<=14*9+1;i++){
          memset(dp,-1,sizeof(dp));
          ans+=recur(0,i,0,i,1);
     }
     cout<<ans<<endl;
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