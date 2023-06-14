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
     ll n,m;
     cin>>n>>m;
     string s[n];
     rep(i,0,n){
          cin>>s[i];
     } 

     ll ans=0;
     vector<ll>flip(n,0);
     for(int j=m-1;j>=0;j--){ 

          ll ct1=0,ct2=0;
          for(int i=0;i<n;i++){
               if(flip[i]%2==1){
                    if(s[i][j]=='1') s[i][j]='0';
                    else s[i][j]='1';
               }
               if(s[i][j]=='1') ct1++;
               else ct2++;
          }
          if(ct1>ct2){
               ans+=ct2;
               for(int i=0;i<n;i++){
                    if(s[i][j]=='1') flip[i]++;
               }
          }
          else{
               ans+=ct1;
               for(int i=0;i<n;i++){
                    if(s[i][j]=='0') flip[i]++;
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