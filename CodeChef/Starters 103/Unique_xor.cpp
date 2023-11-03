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
     vector<vl>v(k,vl(2,0));
     string s;
     cin>>s;
     for(int i=0;i<n;i++){
          v[(i+1)%k][s[i]-'0']++;
     }
     ll one=0,zero=0;
     for(int i=0;i<k;i++){

          if(v[i][1]>0) one+=v[i][0];
          else one+=1e6;

          if(v[i][1]%2==0){
               zero+=v[i][1]/2;
          }else{
               zero+=(v[i][1]+1)/2;
               zero++;
          }
     }
     cout<<min(one,zero)<<endl;
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