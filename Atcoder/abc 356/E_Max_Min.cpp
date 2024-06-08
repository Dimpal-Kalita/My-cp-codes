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


const int N=2e6+30;
void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     vl cnt(N+1);
     vl freq(N+1);
     for(auto x:v) cnt[x]++,freq[x]++;
     rep(i,1,N) cnt[i]+=cnt[i-1];
     ll ans=0;
     for(int i=1;i<N;i++){
          ll sum=(freq[i]*(freq[i]-1))/2;
          for(int j=2*i;j<N;j+=i){
               if(j==2*i) sum+=(((j-1)/i)*(cnt[j-1]-cnt[j-i]))*freq[i];
               else sum+=(((j-1)/i)*(cnt[j-1]-cnt[j-i-1]))*freq[i];
          }
          ans+=sum;
     }
     cout<<ans<<endl;
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