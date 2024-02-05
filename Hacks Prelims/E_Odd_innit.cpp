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

/*

missing `to` in `We need you select 2 subsequences` 
*/
void dk(){
     ll n;
     cin>>n;
     assert(n>=2 and n<=1e5);
     ll odd=0;
     rep(i,0,n){
         ll x;
         cin>>x;
         assert(x>=0 and x<=1e9);
         if(x%2) odd++;
     }
     if(odd%2 || odd==0){
          cout<<"NO"<<endl;
          return;
     }
     cout<<"YES"<<endl;
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