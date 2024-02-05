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

bool check(vl v){
     ll n=sz(v);
     set<ll>st;
     ll sum=0;
     for(int i=0;i<n;i++){
          sum+=v[i];
          if(st.count(sum)) return 1;
          st.insert(sum);
     }
     return 0;
}

void dk(){
      ll n;
      cin>>n;
      vl v(n);
      inp(v);
      ll sum=0;
      set<ll>st;
      st.insert(sum);
      for(int i=0;i<n;i++){
           if(i%2) sum-=v[i];
           else sum+=v[i];
           if(st.count(sum)){
               cout<<"YES"<<endl;
               return;
           }
           st.insert(sum);
      }
      cout<<"NO"<<endl;
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