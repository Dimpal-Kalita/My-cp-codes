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
     map<ll,ll>mp;
     rep(i,0,n){
          cin>>v[i];
          mp[v[i]]++;
     }
     priority_queue<pll,vector<pll>,greater<pll>>pq;
     rep(i,0,n+1){
          if(mp.count(i))
               pq.push({mp[i],i});
     }
     vl ans;
     while(sz(pq)){
          ll frq=pq.top().F;
          ll val=pq.top().S;
          pq.pop();
          ans.pb(val);
          frq--;
          ll frq2=0,val2=0;
          if(pq.size()){
               frq2=pq.top().F;
               val2=pq.top().S;
               frq2--;
               pq.pop();
          }
          if(frq2!=0){
               pq.push({frq2,val2});
          }
     }
     set<ll>st;
     ll mex=0;
     sort(all(ans));
     for(auto i:ans){
          st.insert(i);
          if(st.count(mex)){
               mex++;
          }
     }
     cout<<mex<<endl;
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