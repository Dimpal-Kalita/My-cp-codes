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
//13752992
//14012784


void dk(){
     string a,b;
     cin>>a>>b;
     ll n=a.length();
     bool greatera=1;
     for(int i=0;i<n;i++){
          if(a[i]==b[i]) continue;
          if(greatera){
               if(a[i]<b[i]){
                    swap(a[i],b[i]);
               }
               greatera^=1;
          }else{
               if(a[i]>b[i]){
                    swap(a[i],b[i]);
               }
          }
     } 
     cout<<a<<endl;
     cout<<b<<endl;
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