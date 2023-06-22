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
     ll n,k;
     cin>>n>>k;
     map<char,ll> mp={ {'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};

     ll ct=0;
     string s;
     cin>>s;

     for(auto it:s){
          if(mp.count(it)) ct++;
     } 

     if(ct%k){
          cout<<0<<endl;
          return;
     }

     ll ans=1, v=0, last=ct/k;
     for(int i=0;i<n;i++){
          if(mp.count(s[i])) v++;
          if(v>0 and v%k==0 and last>1){
               ll j=i+1,cnt=1;
               while(!mp.count(s[j])){
                    j++;
                    cnt++;
               }
               ans= (ans*cnt)%md;
               i=j-1;
               last--;
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