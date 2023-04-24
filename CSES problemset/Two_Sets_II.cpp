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
 
int n,val;
const int N=1e5;
int dp[501][N];
 
int recur(int ind, int sum){
    if(ind>n || sum>val) return 0;
    if(sum==val) return 1;
    if(dp[ind][sum]!=-1) return dp[ind][sum]; 
    int p= recur(ind+1, sum+ind);
    int np= recur(ind+1, sum);
    return dp[ind][sum]=(p+np)%md;
}
 
 
void dk(){
    cin>>n;
    if(((n*(n+1))/2)%2!=0){
        cout<<0<<endl;
        return;
    }
    memset(dp,-1,sizeof(dp));
    val= (n*(n+1))/4;
    cout<<recur(1,0)<<endl;
}
 
 
 
#undef int
int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
} 