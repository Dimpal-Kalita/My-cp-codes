/**
 * 
 * author: Dimpal Kalita
 * date: 23/04/2023 13:41:25
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


const int N=101;
vl v(N);
ll totsum=0,n;
vector<vl>dp(N,vl (2e5+7,-1));

bool recur(ll ind,ll sum){

     // cout<<ind<<" "<<sum<<endl;
     if(sum==0) return 1;
     if(ind>=n || sum<0) return 0;

     if(dp[ind][sum]!=-1) return dp[ind][sum];
     return dp[ind][sum]=(recur(ind+1,sum)||recur(ind+1,sum-v[ind]));

}

void dk(){
      cin>>n;
      ll odd=0;
      rep(i,0,n){
          cin>>v[i];
          totsum+=v[i];
          if(v[i]%2) odd=i+1;
      }

      if(totsum%2){
          cout<<0<<endl;
          return;
      }

      bool flag= recur(0,totsum/2);

      if(!flag){
          cout<<0<<endl;
          return;
      }
      if(odd){
          cout<<1<<endl;
          cout<<odd<<endl;
          return;
      }

      ll mn=20,ans=-1;
      for(int i=0;i<n;i++){
          ll x=v[i],ct=0;
          while(x%2==0){
               x/=2;
               ct++;
          }
          if(ct<mn){
               mn=ct;
               ans=i+1;
          }
      }
      cout<<1<<endl;
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}