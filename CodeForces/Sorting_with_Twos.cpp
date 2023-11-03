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
     ll last=0;
     for(int i=0;i<=20;i++){
           vl temp;
           for(int j=last;j<(1<<i);j++){
               if(j>=n) break;
               temp.pb(v[j]);
           }
          //  for(auto x:temp){
          //      cout<<x<<" ";
          //  }
          //  cout<<endl;
           if(!is_sorted(all(temp))){
               cout<<"NO"<<endl;
               return;
           }
           last=(1<<i);
     } 
     cout<<"YES"<<endl;
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