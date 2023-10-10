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
     multiset<ll>st;
     ll ans=0;
     for(int i=0,j=0;i<n;i++){
          auto cond=[&](ll mn, ll mx)->bool{
               if(v[i]<=mn){
                    if(mn%v[i]==0) return 1;
               }
               if(v[i]>=mx){
                    if(v[i]%mx==0) return 1;
               }
               if(v[i]%mn==0 and mx%v[i]==0) return 1;
               return 0;
          };
          while(st.size() and !cond(*st.begin(),*st.rbegin())){
               st.erase(st.find(v[j]));
               j++;
          }
          st.insert(v[i]);
          ll x=st.size()*(*st.begin());
          if(x==12){
               cout<<j<<" "<<i<<endl;
          }
          ans=max(ans,x);
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