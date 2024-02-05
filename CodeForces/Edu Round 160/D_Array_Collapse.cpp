#include<bits/stdc++.h>
using namespace std;

#define md                  998244353
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
     stack<ll> st;
     vector<ll>dp(n+1,0);
     ll mn=*min_element(all(v));
     ll ind=-1;
     for(int i=0;i<n;i++){
          if(v[i]==mn){
               ind=i;
               break;
          }
     }
     dp[ind]=1;
     st.push(ind);
     for(int i=ind-1;i>=0;i--){
         while(!st.empty() && v[st.top()]>=v[i]){
              st.pop();
         }
         if(st.empty()){
               dp[i]=(1+dp[i+1])%md;
         }else{
               dp[i]=(dp[i+1]+dp[st.top()])%md;
         }
         st.push(i);
     }

     while(!st.empty()) st.pop();
     st.push(ind);
     vector<ll>dp2(n+1,0);
     dp2[ind]=1;
     for(int i=ind+1;i<n;i++){
          while(!st.empty() && v[st.top()]>=v[i]){
               st.pop();
          }
          if(st.empty()){
               dp2[i]=(1+dp2[i-1])%md;
          }else{
               dp2[i]=(dp2[i-1]+dp2[st.top()])%md;
          }
          st.push(i);
     }
     // cout<<dp[0]<<" "<<dp2[n-1]<<endl;
     cout<<(dp[0]*dp2[n-1])%md<<endl;
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