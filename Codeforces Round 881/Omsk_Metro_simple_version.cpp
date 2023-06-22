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
     vector<ll>mx(n+5,0), mn(n+5,0), valmx(n+5,0),valmn(n+5,0);
     ll ct=1;
     mx[1]=1;
     mn[1]=0;
     valmx[1]=1;
     valmn[1]=0;
     rep(i,0,n){
          char ch;
          cin>>ch;
          if(ch=='+'){
               ll x,y;
               cin>>x>>y;
               ct++;
               
               if(valmx[x]+y<0){
                    valmx[ct]=valmx[x];
               }else{
                    valmx[ct]=valmx[x]+y;
               }

               mx[ct]=max(mx[x],valmx[ct]);

               if(valmn[x]+y>0){
                    valmn[ct]=valmn[x];
               }else{
                    valmn[ct]=valmn[x]+y;
               }

               mn[ct]=min(mn[x],valmn[ct]);

          }else{

               ll u,v,x;
               cin>>u>>v>>x;
               
               if(x>=mn[v] && x<=mx[v]){
                    cout<<"YES\n";
               }else{
                    cout<<"NO\n";
               }
          }
     }   

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