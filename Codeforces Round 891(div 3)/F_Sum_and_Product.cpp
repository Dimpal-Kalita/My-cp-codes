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

bool isPerfectSquare(ll x){
     ll s=sqrtl(x);
     return (s*s!=x);
}

void dk(){
     ll n;
     cin>>n;
     vl v(n);
     map<ll,ll>mp;
     for(auto i:v) cin>>i,mp[i]++;
     
     ll q;
     cin>>q;
     while(q--){
          ll x,y;
          cin>>x>>y;
          ll val=x*x-4*y;
          // cerr<<val<<endl;
          if(isPerfectSquare(val)){
               cout<<"0"<<" ";
               continue;
          }
          ll s=sqrtl(val);
          ll a=(x+s)/2,b=x-a;
          ll ans=0;
          ll ct1=mp[a],ct2=mp[b];
          // cerr<<a<<" "<<b<<endl;
          if(a==b){
               ans+=(ct1*(ct1-1))/2;
          }else{
               ans+=ct1*ct2;
          }
          ll c=(x-s)/2,d=x-c;
          ct1=mp[c],ct2=mp[d];
          if(c!=a and c!=b){
               if(c==d){
                    ans+=(ct1*(ct1-1))/2;
               }
               else{
                    ans+=ct1*ct2;
               }
          }
          cout<<ans<<" ";
     }
     cout<<endl;
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