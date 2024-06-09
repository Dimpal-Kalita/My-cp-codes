/**
 * 
 * author: Dimpal Kalita
 * date: 08/06/2024 17:11:26
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


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<pair<int,int>>vp;
        int n=nums.size();
        for(int i=0;i<n;){
               int j=i,cnt=0;
               while(j<n && nums[j]==nums[i]){
                    j++;
                    cnt++;
               }
               vp.push_back({nums[i],cnt});
               i=j;
        }
        n=vp.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        function<vector<int>(int,int)> solve=[&](int ind,int last)->vector<int>{
                 if(ind==n) return {0,0};
                 if(dp[ind][last]!=vi{-1,-1}) return dp[ind][last];
                 vector<int> np=solve(ind+1,last);
                 vector<int> p= solve(ind+1,ind);
                 p[0]+=vp[ind].second;
                 if(vp[ind].first!=vp[last].first) p[1]+=1;
                 if(p[1]<=k and p[0]>np[0]){
                    dp[ind][last]=p;
                 }else{
                     dp[ind][last]=np;
                 }
                 return dp[ind][last];
        };
        int ans=0;
        for(int i=0;i<n;i++){
               auto x=solve(i+1,i);
               ans=max(ans,x[0]+vp[i].second);
        }
            return ans;
    }
};

void dk(){
     ll n;
     cin>>n;
     vi v(n);
     inp(v);
     ll k;
     cin>>k;
     Solution s;
     cout<<s.maximumLength(v,k)<<endl;
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