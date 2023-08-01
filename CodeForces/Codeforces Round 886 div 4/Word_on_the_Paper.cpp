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


bool check(char a){
     if(a>='a' and a<='z') return 1;
     return 0;
}

void dk(){
     vector<string>s(8);
     rep(i,0,8){
          cin>>s[i];
     }

     rep(i,0,8){
          rep(j,0,8){
               if(check(s[i][j])){
                    string ans="";
                    while(i<8 and check(s[i][j])){
                         ans+=s[i][j];
                         i++;
                    }
                    cout<<ans<<endl;
                    return;
               }
          }
     }
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