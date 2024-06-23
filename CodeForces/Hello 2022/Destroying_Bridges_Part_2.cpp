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
     ll n,c;
     cin>>n>>c;
     vl v(n);
     inp(v);
     ll ans=n;
     ll y=0;
     for(int i=1;i<n;i++) y+=v[0]*v[i];
     if(y<=c){
          cout<<1<<endl;
          return;
     }
     set<pll>st;
     for(int i=0;i<n;i++){
          ll x=0;
          for(int j=0;j<n;j++){
               if(j==i) continue;
               x+=v[i]*v[j];
          }
         st.insert({x,i});
     }
     // cout<<"------"<<endl;
     set<ll>d;
     for(auto i:st){
          ll x=i.first;
          for(auto j:d){
               x-= 2*v[i.S]*v[j];
          }
          if(x<=c){
               ans--;
               c-=x;
               d.insert(i.S);
          }
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