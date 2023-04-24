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





const int N=1e5+1;
int n;
vi v(101);
vector<vi> dp(101,vi(N,0));

void dk(){
    cin>>n;
    rep(i,0,n) cin>>v[i];
    dp[0][0]=1;

    rep(i,0,n){
        dp[i+1]=dp[i];
        rep(j,0,N){
            if(j-v[i]>=0 and  dp[i][j-v[i]]==1){
                dp[i+1][j]=1;
            }
        }
    }
    set<int> st;

    rep(i,1,n+1){
        rep(j,1,N){
            if(dp[i][j]==1){
                st.insert(j);
            }
        }
    }
    cout<<st.size()<<endl;
    for(auto it:st) cout<<it<<" ";
    cout<<endl;
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