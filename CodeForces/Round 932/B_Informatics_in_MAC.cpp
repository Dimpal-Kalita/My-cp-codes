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
     vl ps(n+1),ss(n+1);
     set<ll>st;
     ll mex=0;
     for(int i=0;i<n;i++){
          st.insert(v[i]);
          while(st.count(mex)){
               mex++;
          }
          ps[i+1]=mex;
     }
     st.clear();
     mex=0;
     for(int i=n-1;i>=0;i--){
          st.insert(v[i]);
          while(st.count(mex)){
               mex++;
          }
          ss[i]=mex;
     }
     
     for(int i=1;i<n;i++){
          if(ps[i]==ss[i]){
               cout<<2<<endl;
               cout<<1<<" "<<i<<endl;
               cout<<i+1<<" "<<n<<endl;
               return;
          }
     }
     cout<<-1<<endl;

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