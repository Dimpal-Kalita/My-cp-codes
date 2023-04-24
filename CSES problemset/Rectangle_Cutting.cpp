// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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



int n,m;
vector<vi>dp(501,vi(501,-1));

int recur(int i, int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans=1000; 
   
    for(int k=1;k<=i/2;k++){
        ans= min(ans, recur(i-k,j)+recur(k,j)+1);
    }

    for(int k=1;k<=j/2;k++){
        ans= min(ans,recur(i,j-k)+recur(i,k)+1);
    }
    
    return dp[i][j]=ans;
}

void dk(){
    cin>>n>>m;
    cout<<recur(n,m)<<endl;
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