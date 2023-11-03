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
     string s;
     cin>>s;
     vl ans(n+1,0);
     reverse(all(s));
     int i=0;
     for(;i<n;i++){
          if(s[i]=='1') break;
     }
     ll x=0;
     for(int j=i;i<n;i++,j++){
          ll cnt=x;
          while(j<n and s[j]=='1'){
               cnt++;
               j++;
               x++;
          }
           ans[i+1]=(cnt+ans[i]);
     }
     ll zero=count(all(s),'0');
     rep(i,1,n+1){
          if(i>zero){
               cout<<"-1"<<" ";
               continue;
          }
          cout<<ans[i]<<" ";
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