// 2112048
// Dimpal Kalita

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
#define int                 long long

using pii = pair<int,int>;
using ull = unsigned long long;
using lld = long double;
using vi  = vector<int>;


const int N=2e5+10;
int n;
vector<array<int,3>>v;
vector<int>dp(N,-1);

int recur(int ind){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int ans=0;
    for(int i=ind+1;i<n;i++){
        if(v[i][0]>v[ind][1]){
            ans= max(ans, recur(i));
        }
    }
    return dp[ind]=ans+v[ind][2];
}


void dk(){
    cin>>n;

    map<int,int> mp;

    rep(i,0,n){
        array<int,3>temp;
        rep(j,0,3) cin>>temp[j];
        v.pb(temp);
        rep(j,0,2) mp[temp[j]]++;
    }
    int count=1;

    for(auto &it:mp){
        it.S=count;
        count++;
    }
    rep(i,0,n) rep(j,0,2) v[i][j]=mp[v[i][j]];
    sort(all(v));
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans= max(ans, recur(i));
    }
    cout<<ans<<endl;
}



#undef int
int main()
{ 
    fast_io;
  
    int n=1;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}