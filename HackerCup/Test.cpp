/**
 * 
 * author: Dimpal Kalita
 * date: 22/09/2023 08:34:44
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
#define file_io             freopen("../input.txt", "r+", stdin);freopen("../output.txt", "w+", stdout);

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
     vector<ll> v(n);
     inp(v);
     if(n>2*k){
           cout<<"NO"<<endl;
           return;
     }
     map<ll,ll>mp;
     for(auto x:v){
          mp[x]++;
     }
     for(auto [x,y]:mp){
          if(y>2){
               cout<<"NO"<<endl;
               return;
          }
     }
     cout<<"YES"<<endl;
}



int main()
{ 
    fast_io;
    #ifndef ONLINE_JUDGE
    file_io;
    #endif  
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
     cout<<"Case #"<<i+1<<": ";
    dk();
   }
  return 0;
}