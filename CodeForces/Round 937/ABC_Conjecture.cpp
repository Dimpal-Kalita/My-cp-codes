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
     string a,b;
     cin>>a>>b;
     ll neq=0,can=0;
     rep(i,0,n){
          if(a[i]=='a' and b[i]=='c') neq++;
          else if(a[i]=='b' and b[i]=='b'){
               can+=neq;
               neq=0;
          }
          else if(a[i]=='c' and b[i]=='a'){
               if(can==0){
                    cout<<"No"<<endl;
                    return;
               }
               can--;
          }else if(a[i]!=b[i]){
               cout<<"No"<<endl;
               return;
          }
     } 
     if(can or neq){
          cout<<"No"<<endl;
          return;
     }
     cout<<"Yes"<<endl;
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