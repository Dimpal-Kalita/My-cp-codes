#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
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


char query(ll a,ll b,ll c,ll d){
     cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
     char x;
     cin>>x;
     return x;
}
void dk(){
     ll n;
     cin>>n;
     ll ind=0;
     for(int i=1;i<n;i++){
          char ch=query(i,i,ind,ind);
          if(ch=='>') ind=i; 
     }
     ll cur=0;
     vl v={0};
     for(int i=1;i<n;i++){
          if(i==ind) continue;
          char ch=query(ind,i,ind,cur);
          if(ch=='>'){
               v.clear();
               v.pb(i);
               cur=i;
          }
          if(ch=='=') v.pb(i);
     }
     cur=v[0];
     for(auto i:v){
          if(i==cur) continue;
          char ch=query(cur,cur,i,i);
          if(ch=='>') cur=i;
     }
     cout<<"! "<<ind<<" "<<cur<<endl;
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