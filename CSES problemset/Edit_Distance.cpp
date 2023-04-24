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


const int N=5e3+5;
int n, m;
string s, t;
vector<vi>dp(N, vi(N,-1));

int recur(int i, int j){

    if(i==n and j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(j==m){
        int ans=0;
        while(i<n){
            i++;
            ans++;
        }
        return dp[i][j]=ans;
    }

    if(i==n){
        int ans=0;
        while(j<m){
            j++;
            ans++;
        }
        return dp[i][j]=ans;
    }

    int ans=0;
    if(s[i]==t[j]) ans=recur(i+1, j+1);
    else{

        int repl= recur(i+1,j+1)+1;
        int ins= recur(i,j+1)+1;
        int del= recur(i+1, j)+1;
        ans= min({repl,ins,del});
    }

    return dp[i][j]=ans;
}



void dk(){
    cin>>s>>t;
    n=s.length();
    m=t.length();
    cout<<recur(0,0)<<endl;
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