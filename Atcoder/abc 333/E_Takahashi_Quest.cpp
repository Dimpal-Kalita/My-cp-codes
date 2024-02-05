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
     vector<pll>vp;
     rep(i,0,n){
          ll t,x;
          cin>>t>>x;
          vp.pb({t,x});
     }
     reverse(all(vp));
     vl v;
     map<ll,ll>mp,pick;
     for(int i=0;i<vp.size();i++){
          int t=vp[i].first,x=vp[i].second;
          if(t==1){
               if(mp[x]>0){
                    pick[vp.size()-i-1]=1;
                    v.pb(1);
                    mp[x]--;
               }else{
                    v.pb(0);
               }
          }else{
               mp[x]++;
          }
     }
     mp.clear();
     ll ans=0,ct=0;
     reverse(all(vp));
     reverse(all(v));

     for(int i=0;i<vp.size();i++){
          int t=vp[i].first,x=vp[i].second;
          if(t==1){
               if(pick[i]){
                    mp[x]++;
                    ct++;
               }
          }else{
               if(mp[x]==0){
                    cout<<-1<<endl;
                    return;
               }
               mp[x]--;
               ct--;
          }
          ans=max(ans,ct);
     }
     cout<<ans<<endl;
     for(auto i:v){
          cout<<i<<" ";
     }
     cout<<endl;

}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   