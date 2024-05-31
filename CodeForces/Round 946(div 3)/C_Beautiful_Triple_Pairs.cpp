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
      inp(v);
      map<array<ll,2>,ll>mp1;
      map<array<ll,3>,ll>mp2;
      // a1!=b1, 
      ll ans=0;
      for(int i=2;i<n;i++){
          ans+=mp1[{v[i],v[i-1]}]-mp2[{v[i],v[i-1],v[i-2]}];
          mp1[{v[i],v[i-1]}]++;
          mp2[{v[i],v[i-1],v[i-2]}]++;
      }
      // a2!=b2
      mp1.clear();
      mp2.clear();
     for(int i=2;i<n;i++){
          ans+=mp1[{v[i],v[i-2]}]-mp2[{v[i],v[i-1],v[i-2]}];
          mp1[{v[i],v[i-2]}]++;
          mp2[{v[i],v[i-1],v[i-2]}]++;
      }
      // a3!=b3
      mp1.clear();
      mp2.clear();
     for(int i=2;i<n;i++){
          ans+=mp1[{v[i-1],v[i-2]}]-mp2[{v[i],v[i-1],v[i-2]}];
          mp1[{v[i-1],v[i-2]}]++;
          mp2[{v[i],v[i-1],v[i-2]}]++;
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