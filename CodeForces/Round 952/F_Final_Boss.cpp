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
     ll h,n;
     cin>>h>>n;
     vl a(n),b(n);
     inp(a);
     inp(b);
     auto check=[&](ll t)->bool{
          ll H=h;
          for(int i=0;i<n;i++){
               ll x=(t-1)/b[i]+1;
               H-=(x*a[i]);
               // cout<<x*a[i]<<" ";
               // cout<<H<<endl;
               if(H<=0){
                    return true;
               }
          }
          return false;
     };
     // cout<<check(1)<<endl;
     ll l=1,r=1e13;
     while(l<r){
          ll m=(l+r)/2;
          if(check(m)){
               r=m;
          }else{
               l=m+1;
          }
     }
     cout<<l<<endl;
}



int main()
{ 
    fast_io;
//     freopen("input.txt", "r+", stdin);
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   