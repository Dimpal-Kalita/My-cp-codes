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
     ll n,m;
     cin>>n>>m;
     vl a(n),b(n);
     rep(i,1,n) cin>>a[i];
     inp(b);
     sort(all(a));
     sort(all(b));
     auto check2=[&](ll y){
          a[0]=y;
          auto check=[&](ll x)->bool{
               for(int i=0,j=n-x-1;j<n;i++,j++){
                    if(a[i]>=b[j]) return 0;
               }
               return 1;
          };
          ll l=0,r=n,ans=n;
          while(l<r){
               ll mid=(l+r)/2;
               if(check(mid)){
                    ans=n-mid-1;
                    l=mid+1;
               }
               else r=mid;
          }
          return ans;
     };

     ll fix=check2(1);
     ll l=1,r=m+1;
     while(l<r){
          ll mid=(l+r)/2;
          if(check2(mid)<fix)r=mid;
          else l=mid+1;
     }
     ll ans= fix*(r)+(fix-1)*(m-r);
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