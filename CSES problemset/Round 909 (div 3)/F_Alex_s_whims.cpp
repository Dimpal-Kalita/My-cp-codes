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
     rep(i,0,n-1){
          cout<<i+1<<" "<<i+2<<endl;
     }
     ll q;
     cin>>q;
     ll last=n-1;
     ll a=n,b=n-1;
     while(q--){
          ll d;
          cin>>d;
          if(last==d){
               cout<<-1<<" "<<-1<<" "<<-1<<endl;
               continue;
          }
          cout<<a<<" "<<b<<" ";
          cout<<d-1<<endl;
          a=d;
          last=d;
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