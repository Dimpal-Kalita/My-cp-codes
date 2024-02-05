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


void dk(){
     ll n,x;
     cin>>n>>x;
     vector<ll>ans(n);
     ans[0]=x;
     ans[n-1]=(n+1)-x;
     vector<ll>vis(n+1);
     vis[x]=1;
     vis[(n+1)-x]=1;
     ll start=1;
     for(int i=1,j=n-2;i<=j;i++,j--){
          while(start<n and vis[start]) start++;
          ans[i]=start;
          vis[start]=1;
          if(i==j) break;
          ans[j]=(n+1)-start;
          vis[(n+1)-start]=1;
     }
     set<ll>st={ans.begin(),ans.end()};
     if(st.size()!=n){
          cout<<-1<<endl;
          return;
     }
     for(auto i:ans) cout<<i<<" ";
     cout<<endl;
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