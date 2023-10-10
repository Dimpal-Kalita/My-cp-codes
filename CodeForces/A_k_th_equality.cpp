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


void out(ll a,ll b){
     ll c=a+b;
     cout<<a<<" + "<<b<<" = "<<c<<endl;
     return;
}

void dk(){
     ll a,b,c,k;
     cin>>a>>b>>c>>k;
     ll l=pow(10,a-1),r=pow(10,a);
     for(int i=l;i<r;i++){
          ll mn=pow(10,c-1);
          ll x=pow(10,b-1);
          ll start=max(mn-i,x);
          ll tot=max(0LL,min((ll)pow(10,b),(ll)pow(10,c)-i)-start);
          if(k<=tot){
               out(i,start+k-1);
               return;
          }

          k-=tot;
     }
     cout<<"-1"<<endl;
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