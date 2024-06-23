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

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;




void dk(){
     ll n,m;
     cin>>n>>m;
     vector<vl>v(n,vl(m));
     ll N=n+m-1;
     vl cnt(N+1,0);
     vl total(N+1,0);
     rep(i,0,n){
          rep(j,0,m){
               cin>>v[i][j];
               cnt[i+j]+=v[i][j];
               total[i+j]++;
          }
     }
     ll ans=0;
     for(int i=0;i<N/2;i++){
          ll zerol=total[i]-cnt[i];
          ll onel=cnt[i];
          ll zeror=total[N-i-1]-cnt[N-i-1];
          ll oner=cnt[N-i-1];
          ans+=min(zerol+zeror,onel+oner);
          // cout<<zerol<<" "<<zeror<<" "<<onel<<" "<<oner<<endl;
     }
     cout<<ans<<endl;
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