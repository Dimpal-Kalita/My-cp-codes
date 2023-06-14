/**
 * 
 * author: Dimpal Kalita
* 
 */

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
     ll ans=0;
     multiset<ll> st;
     vl tt=v;
     for(int _=0;_<2;_++){

          for(int i=0;i<v.size();i++){
               st.insert(v[i]-i);
          }
          
          vector<ll> temp;

          for(int i=0;i<v.size();i++){
              ll val=v[i]-i;


              if(st.count(val)) st.erase(st.find(val));

              if(st.size()==0) continue;
              ll mx=*st.rbegin();
              temp.pb(tt[i]+i+mx);

          }
          v.clear(); 
          v=temp;
     }
     cout<<*max_element(all(v))<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}