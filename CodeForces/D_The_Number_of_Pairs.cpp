/**
 * 
 * author: Dimpal Kalita
 * date: 30/06/2023 22:35:06
 * 
 */

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

//  gcd(a,b)=g
// c*(a*b)= g*(x+d*g)
// c*(a/g*b/g)=x/g+d
// (a/g*b/g)= (x/g+d)/c
// if (x/g+d)/c= k , to count pair  (a/g*b/g)  we have to just select the number of prime divisors of k
// and apply pick not pick for every prime divisor of k. hence number of pairs= 2^(primedivisors);



vector<int>calc(ll n){
     // to calculate the number of prime divisor of every number faster
     vector<int>ans(n+1,0);
     for(int i=2;i<=n;i++){
         if(ans[i]==0){
             for(int j=i;j<=n;j+=i){
                 ans[j]++;
             }
         }
     }
     return ans;
}

vector<int>prime=calc(2e7);

void dk(){
     int c,d,x;
     cin>>c>>d>>x;
     ll ans=0;
     for(int g=1;g*g<=x;g++){
          if(x%g==0){
               ll a=g+d;
               ll b=x/g+d;
               if(a%c==0){
                    ans+=1<<prime[a/c];
               }
               if(g*g!=x){
                    if(b%c==0){
                         ans+=1<<prime[b/c];
                    }
               }
          }
     }
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}