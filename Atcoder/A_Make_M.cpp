/**
 * 
 * author: Dimpal Kalita
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


void dk(){
     ll n;
     cin>>n;
     vl v(n);
     map<ll,ll> mp;
     for(int i=0;i<n;i++){
         cin>>v[i];
         mp[v[i]]++;
     }

     ll ct=0;
     for(auto it:mp){
          ll x=it.S;
          ll big= n-it.S-ct;
          ll small=ct;
          if(small>=x+1 || big>=x-1 || (x==n/2 and big>0 and ct>0)){
               ct+=x;
               continue;
          }
          cout<<"No"<<endl;
          return;
     }
     cout<<"Yes"<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}