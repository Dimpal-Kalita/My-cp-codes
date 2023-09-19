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
     string s,t;
     cin>>s>>t;
     ll ans=0;
     for(int a=0;a<n;a++){
          for(int b=a;b<n;b++){
               for(int c=0;c<n;c++){
                    for(int d=c;d<n;d++){
                         string temp=s;
                         for(int i=a;i<=b;i++){
                              temp[i]=(temp[i]=='0'?'1':'0');
                         }
                         for(int i=c;i<=d;i++){
                              temp[i]=(temp[i]=='0'?'1':'0');
                         }
                         if(temp==t){
                              // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                              ans++;
                         }
                    }
               }
          }
     } 
     cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}