/**
 * 
 * author: Dimpal Kalita
 * date: 19/05/2023 23:39:00
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


const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vector<int> primeSieve(int lim) {
     isprime.set();
     isprime[0] = isprime[1] = 0;
     for (int i = 4; i < lim; i += 2) isprime[i] = 0;
     for (int i = 3; i * i < lim; i += 2)
          if (isprime[i])
               for (int j = i * i; j < lim; j += i * 2) isprime[j] = 0;
     vector<int> pr;
     for (int i = 2; i < lim; i++)
          if (isprime[i]) pr.push_back(i);
     return pr;
}
vector<int> prime=primeSieve(100000+3);


void dk(){
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);
     ll x=count(all(v),1);
     ll ans=0;
     for(int i=0;i<n;i++){
          if(binary_search(all(prime),v[i])){
               ans+= (x*(x-1))/2;
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