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
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);
#define int                 long long

using pii = pair<int,int>;
using ull = unsigned long long;
using lld = long double;
using vi  = vector<int>;


const int N=1e5+1;
int n, m;
vector<int> v(N);
vector<vector<int>>dp(N, vector<int>(101,-1));

int recur(int ind, int prev){

    if(ind==n) return 1;
    if(dp[ind][prev]!=-1) return dp[ind][prev];

    int ans=0;
    if(v[ind]==0){
        for(int i=prev-1;i<=prev+1;i++){
            if(i>0 and i<=m)
                ans= (ans+recur(ind+1,i))%md;
        }
    }
    else{
        if(abs(v[ind]-prev)>1) ans=0;
        else{
            ans= (ans+recur(ind+1, v[ind]))%md;
        }
    }

    return dp[ind][prev]=ans;
}

void dk(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=0;
    if(v[0]==0){
        for(int i=1;i<=m;i++){
            ans= (ans+recur(1,i))%md;
        }
    }else{
        ans=recur(1,v[0]);
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