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
      vl v(3);
      inp(v);
      sort(all(v),greater<ll>());
      ll A=0;
      for(int i=0;i<3;i++){
          A=A*10+v[i];
      }
      inp(v);
      sort(all(v),greater<ll>());
      ll B=0;
      for(int i=0;i<3;i++){
          B=B*10+v[i];
      }
      if(A>B) cout<<"Alice"<<endl;
      else if(B>A) cout<<"Bob"<<endl;
      else cout<<"Tie"<<endl;
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