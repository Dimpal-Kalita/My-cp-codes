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
     ll n,f,a,b;
     cin>>n>>f>>a>>b;
     vl v(n);
     inp(v);
     ll last=0; 
     ll ans=0;
     for(int i=0;i<n;i++){
          ll dif=v[i]-last;
          f-=min(dif*a,b);
          // cout<<dif*a<<" "<<b<<" "<<f<<endl;
          if(f<=0){
               cout<<"NO"<<endl;
               return;
          }
          last=v[i];
          ans++;
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