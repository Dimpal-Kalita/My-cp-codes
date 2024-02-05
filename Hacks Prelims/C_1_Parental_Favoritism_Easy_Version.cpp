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

n is not mentioned;

statement is not clear to be reviewed later 

*/


void dk(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     ll q;
     cin>>q;
     assert(n>=1 and n<=26);
     while(q--){
          ll l1,r1,l2,r2;
          cin>>l1>>r1>>l2>>r2;
          ll l=min(l1,l2),r=max(r1,r2);
          cout<<(l1-l)*2+(l2-l)*2+(r-r1)+(r-r2)<<endl;
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