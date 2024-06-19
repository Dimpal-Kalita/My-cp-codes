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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n,c;
     cin>>n>>c;
     vl v(n);
     inp(v);
     ll mx=*max_element(all(v));
     vl ps(n,0),ss(n,0); 
     for(int i=0;i<n;i++){
          if(i-1>=0){
               if(v[i-1]==mx or ps[i-1]) ps[i]=1;
          }
     }
     for(int i=n-1;i>=0;i--){
          if(i+1<n){
               if(v[i+1]==mx or ss[i+1]) ss[i]=1;
          }
     }
     // debug(ps);
     // debug(ss);
     ll sum=c;
     for(int i=0;i<n;i++){
          sum+=v[i];
          if(ps[i]){
               cout<<i<<" ";
          }else if(ss[i]){
               if(v[i]==mx){
                    if(v[0]+c>=mx){
                         cout<<i<<" ";
                    }else{
                         cout<<0<<" ";
                    }
                    continue;
               }
               if(sum>=mx){
                    cout<<i<<" ";
               }else{
                    cout<<i+1<<" ";
               }
          }else{
               if(v[0]+c>=mx){
                    cout<<i<<" ";
               }else{
                    cout<<0<<" ";
               }
          }
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