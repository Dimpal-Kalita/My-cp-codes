/**
 * 
 * author: Dimpal Kalita
 * date: 26/05/2023 21:32:29
 * 
 */

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


 
ll nCr(int n, int r) {
     long double sum=1;
     for(int i = 1; i <= r; i++){
          sum = sum * (n - r + i) / i;
     }
     return sum;
}
 


void dk(){
      ll n;
      cin>>n;
      ll ans=0;
      ans= nCr(n,5)+nCr(n,7)+nCr(n,6);
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}