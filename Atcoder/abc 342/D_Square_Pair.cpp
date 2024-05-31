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


const int N=3e5;
vector<ll> store(N+1),prime(N+1);

void sieve(){
     for(int i=1;i<=N;i++)  store[i]=i;

      for (int i = 2; i <= N; i++) {
        if (prime[i] == 0)
            for (int j = i; j <= N; j += i) {
 
                prime[j] = 1;
                while (store[j] % (i * i) == 0)
                    store[j] /= (i * i);
            }
    
    }
}
void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll ct=0;
     map<ll,ll>mp;
     for(auto i:v){
          if(i==0){
               ct++;
               continue;
          }
          mp[store[i]]++;
     } 
     ll ans=0;
     for(auto [x,y]:mp){
          ans+=(y*(y-1))/2;
     }
     ans+=(ct*(n-ct))+ct*(ct-1)/2;
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
    sieve();
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   