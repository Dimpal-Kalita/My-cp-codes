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





ll expo(ll b,ll e){
     ll ans=1;
     for(;e;b=(b*b)%md,e/=2){
          if(e&1) ans=(ans*b)%md;
     }
     return ans;
}

ll dp[70][1<<19];
vector<ll>prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
void dk(){
     ll n;
     cin>>n;
     vl v;
     map<ll,ll>mp1,mp,msk;
     rep(i,0,n){
          ll x;
          cin>>x;
          mp1[x]++;
     }
     for(auto [x,y]:mp1){
          v.pb(x);
     }

     for(auto &i:v){
           ll x=i;
           ll mask=0;
           for(int j=0;j<19;j++){
                while(x%prime[j]==0){
                     mask^=(1<<j);
                     x/=prime[j];
                }
           }
           mp[i]+=mp1[i];
           msk[i]=mask;
     }
     
     memset(dp,-1,sizeof(dp));
     auto recur=[&](auto recur,ll ind, ll mask)->ll{
           if(ind==v.size()){
               if(mask==0) return 1;
               return 0;
           }
           if(dp[ind][mask]!=-1) return dp[ind][mask];
           ll ct=mp[v[ind]];
           ll np=(recur(recur,ind+1,mask)*expo(2,ct-1))%md;
           ll p=(recur(recur,ind+1,mask^msk[v[ind]])*expo(2,ct-1))%md;
           return dp[ind][mask]=(p+np)%md;
     };
     cout<<(recur(recur,0,0)-1+md)%md<<endl;
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