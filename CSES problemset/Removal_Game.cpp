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



const int N=5e3+1;
int n;
vi v(N);
vector<vi>dp(N,vi(N,-1));
int recur(int i, int j){

    if(j<i || i>=n || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int left= v[i]+ min(recur(i+2,j),recur(i+1,j-1));
    int right= v[j]+ min(recur(i,j-2),recur(i+1,j-1));

    return dp[i][j]=max(left, right);
}



void dk(){
    cin>>n;
    rep(i,0,n) cin>>v[i];
    cout<<recur(0,n-1)<<endl;
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