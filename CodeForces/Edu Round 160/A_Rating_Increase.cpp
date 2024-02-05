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
     string s;
     cin>>s;
     int n=s.size();
     for(int i=0;i<n;i++){
         string x=s.substr(0,i+1);
         string y=s.substr(i+1,n-i-1);
         if(y.size()==0) continue;
         if(y[0]=='0') continue;
         ll a=stoll(x);
         ll b=stoll(y);
         if(b>a){
           cout<<a<<" "<<b<<endl;
          return;
         }
     }
     cout<<"-1"<<endl;
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