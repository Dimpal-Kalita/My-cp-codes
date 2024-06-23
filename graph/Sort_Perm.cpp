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
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     set<int>st;
     ll mx=0;
     ll l=0;
     for(int i=0;i<n;i++){
          if(mx>v[i]){
               st.insert(i);
               l=max(l,mx-v[i]);
          }
          mx=max(mx,v[i]);
     }
     ll r=n;
     bool flag=0;
     vl vp=vl(all(st));
     for(int i=0;i<sz(vp)-1;i++){
          ll mn=n+v[vp[i]],mxx=v[vp[i]];
          ll mnn=n+v[vp[i]];
          for(int j=vp[i]+1;j<vp[i+1];j++){
               if(v[j]>v[vp[i+1]]) mn=min(mn,v[j]);
               else mxx=max(mxx,v[j]);
               mnn=min(mnn,v[j]);
          }
          r=min(r,max(mn-mxx,mnn-v[vp[i]]));
     }
     mx=0;
     for(auto i:st){
          if(mx>v[i]){
               cout<<0<<endl;
               return;
          }
          mx=max(mx,v[i]);
     }
     ll ans=0;
     for(int k=l;k<=r;k++){
          ans+=k;
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