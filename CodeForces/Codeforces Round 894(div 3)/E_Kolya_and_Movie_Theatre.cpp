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
     ll n,m,d;
     cin>>n>>m>>d;
     vl v(n);
     inp(v);
     ll ans=0;
     priority_queue<ll,vector<ll>,greater<ll>> pq;
     ll sum=0;
     for(int i=0;i<n;i++){
          if(v[i]<=0) continue;
          if(pq.size()==m){
               if(v[i]>pq.top()){
                    sum-=pq.top();
                    pq.pop();
                    pq.push(v[i]);
                    sum+=v[i];
                    ans=max(ans,sum-(i+1)*d);
               }
          }else{
               pq.push(v[i]);
               sum+=v[i];
               ans=max(ans,sum-(i+1)*d);
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