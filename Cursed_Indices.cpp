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
     sort(all(v));
     ll ct=0,sum=v[0];
     vector<ll>vis(n+1);
     vector<ll>ans;
     multiset<ll>st={v.begin(),v.end()};
     st.erase(st.find(v[0]));
     ans.pb(v[0]);
     for(int i=1;i<n;i++){
          auto it=st.lower_bound(sum+1);
          if(it!=st.end()){
               sum+=*it;
               ans.pb(*it);
               st.erase(it);
          }else{
               break;
          }
     }
     cout<<st.size()<<endl;
     for(auto i:ans) cout<<i<<" ";
     while(!st.empty()){
          cout<<*st.begin()<<" ";
          st.erase(st.begin());
     }
     cout<<endl;
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