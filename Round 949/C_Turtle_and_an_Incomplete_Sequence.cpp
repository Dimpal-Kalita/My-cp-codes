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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif



void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll ct=0,last=-1;
     vector<array<ll,3>>vp;
     for(int i=0;i<n;i++){
          if(v[i]==-1){
               ct++;
               continue;
          }
          if(last!=-1 and ct!=0){
               vp.pb({last,i,ct});
          }
          last=i;
          ct=0;
     }
     vl ans=v;
     for(auto i:vp){
          ll l=i[0],r=i[1],ct=i[2];
          ll mx=max(v[l],v[r]);
          ll mn=min(v[l],v[r]);
          ll cnt=0;
          ll x=mx,y=mn;
          while(x!=y){
               while(x>y){
                    x/=2;
                    cnt++;
               }
               while(y>x){
                    y/=2;
                    cnt++;
               }
          }
          ll cur=v[l];
          for(int j=l+1;j<r;j++){
               if(cur==x) break;
               cur/=2;
               ans[j]=cur;
          }
          cur=v[r];
          for(int j=r-1;j>l;j--){
               if(cur==x) break;
               cur/=2;
               ans[j]=cur;
          }
          
     }
     debug(ans);
     last=0;
     ll req=0;
     for(int i=0;i<n;i++){
          if(ans[i]!=-1) req=ans[i];
          if(last and ans[i]==-1){
               if(req!=last){
                    last=req;
               }else{
                    last=req*2;
               }
               ans[i]=last;
          }
          if(ans[i]==-1) continue;
          last=ans[i];
     }
     last=0,req=0;
     for(int i=n-1;i>=0;i--){
          if(ans[i]!=-1) req=ans[i];
          if(last and ans[i]==-1){
               if(req!=last){
                    last=req;
                    ans[i]=last;
               }else{
                    last=req*2;
                    ans[i]=last;
               }
          }
          if(ans[i]==-1) continue;
          last=ans[i];
     }
     last=2;
     for(int i=n-1;i>=0;i--){
          if(last and ans[i]==-1){
               if(last%2){
                    last=2*last;
                    ans[i]=last;
               }else{
                    last=last/2;
                    ans[i]=last;
               }
          }
          if(ans[i]==-1) continue;
          last=ans[i];
     }
     for(int i=0;i<n-1;i++){
          bool flag=0;
          if(ans[i]==(ans[i+1]/2) or ans[i+1]==ans[i]/2) flag=1;
          if(!flag or ans[i]==-1){
               cout<<-1<<endl;
               return;
          }
     }
     for(auto i:ans) cout<<i<<" ";
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