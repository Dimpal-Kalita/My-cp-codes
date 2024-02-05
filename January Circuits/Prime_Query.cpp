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
     ll n;
     cin>>n;
     vl v(n);
     vl cnt0(n+1,0),cnt1(n+1,0);
     rep(i,0,n){
         cin>>v[i];
         if(v[i]==0){
             cnt0[i+1]++;
         }
         if(v[i]==1){
             cnt1[i+1]++;
         }
         cnt0[i+1]+=cnt0[i];
         cnt1[i+1]+=cnt1[i];
     }
     ll q;
     cin>>q;
     while(q--){
          ll l,r;
          cin>>l>>r;
          ll one=cnt1[r]-cnt1[l-1];
          ll zero=cnt0[r]-cnt0[l-1];
          ll len=r-l+1;
          cout<<((len*(len-1))/2)-((zero*(zero-1))/2)-one*zero<<endl;
     } 

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