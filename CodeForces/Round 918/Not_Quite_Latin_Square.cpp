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
     vector<string> v(3);
     inp(v);
     rep(i,0,3){
          bool flag=0;
          rep(j,0,3){
               if(v[i][j]=='?') flag=1;
          }
          if(flag){
               vl cnt(3,0);
               rep(j,0,3){
                    if(v[i][j]=='?') continue;
                    cnt[v[i][j]-'A']++;
               }
               rep(j,0,3){
                    if(!cnt[j]){
                         cout<<(char)(j+'A')<<endl;
                    }
               }
          }
     }
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