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






const int N=1e7+5;
vl vp(N,0);
vl prime(N,0);
int sieve(){
     for(int i=2;i<N;i++){
          if(!prime[i]){
               prime[i]=0;
               vp[i]=i;
               for(int j=2*i;j<N;j+=i){
                    if(!prime[j]) vp[j]=i;
                    prime[j]=1;
               }
          }
     }
     return 0;
}


int xxx=sieve();

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll ans=0;
     map<ll,ll>mp;
     for(auto x:v){
          ll ct=0;
          vl div;
          ll xx=sqrt(x);
          if(xx*xx==x) continue;
          while(x>1){
               ll p=vp[x];
               ll c=0;
               while(x%p==0){
                    x/=p;
                    c++;
               }
               if(c%2) div.pb(p);
          }
          if(div.size()%2){
               ll d=1,p=99987;
               for(auto y:div){
                    d=(d+(y*p)%N)%N;
                    p=(p*p)%N;
               }
               mp[d]++;
          }else{
               ans++;
          }
     }
     for(auto x:mp){
          ans=max(ans,x.second);
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