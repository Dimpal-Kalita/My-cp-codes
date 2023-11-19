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
     vl freq(n+1,0);
     vl check(n+1,0);
     for(auto x:v){
         freq[x]++;
         check[x]=1;
     }
     if(freq[1]){
          cout<<0<<endl;
          return;
     }
     vl count(n+1);
     for(int i=2;i<=n;i++){
          for(int j=i;j<=n;j+=i){
              count[i]+=freq[j];
          }
     }
     vl mu(n+1,1);
     for(int i=2;i<=n;i++){
          if(check[i]==0) continue;
          for(int j=2*i;j<=n;j+=i){
               mu[j]-=mu[i];
               check[j]=1;
          }
     }
     ll ans=0;
     for(int i=2;i<=n;i++){
          if(check[i])
               ans+=((count[i]*(count[i]-1))/2)*mu[i];
     }
      
     cout<<(n*(n-1))/2-ans<<endl;
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