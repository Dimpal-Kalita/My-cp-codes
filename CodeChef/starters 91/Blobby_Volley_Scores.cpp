/**
 * 
 * author: Dimpal Kalita
 * date: 24/05/2023 20:01:34
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


void dk(){
      ll n;
      cin>>n;
      string s;
      cin>>s;
      ll ans1=0, ans2=0;
      ll a=1,b=0;
      for(int i=0;i<n;i++){
          if(s[i]=='A'){
               a++;
               b=0;
               if(a>=2) ans1++;
          }else{
               b++;
               if(b>=2) ans2++;
               a=0;
          }

      }
      cout<<ans1<<" "<<ans2<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}