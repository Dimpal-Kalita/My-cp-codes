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
     vl a(n), b(n);
     inp(a);
     inp(b);
     map<ll,ll> ma,mb;


     for(int i=0;i<n;i++){
          ll ct=0, j=i;
          while(j<n and a[j]==a[i]){
               ct++;
               j++;
          }
          ma[a[i]]=max(ma[a[i]],ct);
          i=j-1;
     } 

     for(int i=0;i<n;i++){
          ll ct=0, j=i;
          while(j<n and b[j]==b[i]){
               ct++;
               j++;
          }
          mb[b[i]]=max(mb[b[i]],ct);
          i=j-1;
     }

     ll ans=0;

     for(auto [x,y]:ma){
          ans=max(ans,y+mb[x]);
     }
     for(auto [x,y]:mb){
          ans=max(ans,y+ma[x]);
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