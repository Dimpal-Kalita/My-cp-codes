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
     inp(v);

     ll mn=1e9,last=0, ct=0;
     string ans="";
     mn=v[0];
     for(int i=0;i<n;i++){
          if(ct==0){
               if(v[i]>=last){
                    ans+='1';
                    last=v[i];
               }else if(v[i]<=mn){
                    ans+='1';
                    ct=1;
                    last=v[i];
               }else{
                    ans+='0';
               }
          }
          else if(ct==1){
               if(v[i]>=last and v[i]<=mn){
                    ans+='1';
                    last=v[i];
               }else{
                    ans+='0';
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