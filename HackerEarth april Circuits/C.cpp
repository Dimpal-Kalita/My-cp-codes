// Problem: Busy Airport
// URL: https://www.hackerearth.com/challenges/competitive/april-circuits-23/algorithm/busy-airport-9fa40749/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author: Dimpal Kalita
// 22-04-2023 09:53:34
 
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
    ll n,a,b,c,d;
    cin>>a>>b>>c>>d;
    cin>>n;
    vl v(n);
    inp(v);
    
    priority_queue<ll,vl,greater<ll>> ps,lg;
    
    for(int i=0;i<n;i++){
         ll val=v[i]+a;
         if(ps.size()<b){
             ps.push(val);
         }else{
            ll sm= ps.top();
            ps.pop();
            if(sm<v[i]) ps.push(val);
            else{
                ps.push(sm+a);
                val=sm+a;
            }
         }
         
         
         if(lg.size()<d){
             lg.push(val+c);
         }else{
             ll sm=lg.top();
             lg.pop();
             if(sm<val) lg.push(val+c);
             else{
                 lg.push(sm+c);
             }
         }
         
    }
    ll ans=0;
    while(!lg.empty()){
        ans=max(ans, lg.top());
        lg.pop();
    }
    cout<<ans<<endl;
}
 
 
 
int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}