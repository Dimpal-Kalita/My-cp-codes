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
     vector<string>v(3);
     rep(i,0,3) cin>>v[i];

     rep(i,0,3){
          char ch=v[i][0],ct=0;
          rep(j,0,3){
               if(v[i][j]=='.') continue;
               if(v[i][j]==ch) ct++; 
          }
          if(ct==3){
               cout<<ch<<endl;
               return;
          }
     }
     rep(i,0,3){
          char ch=v[0][i],ct=0;
          rep(j,0,3){
               if(v[j][i]=='.') continue;
               if(v[j][i]==ch) ct++;
          }
          if(ct==3){
               cout<<ch<<endl;
               return;
          }
     }
     if(v[0][0]==v[1][1] and v[1][1]==v[2][2] and v[0][0]!='.'){
          cout<<v[0][0]<<endl;
          return;
     }
     if(v[0][2]==v[1][1] and v[1][1]==v[2][0] and v[0][2]!='.'){
          cout<<v[0][2]<<endl;
          return;
     }
    cout<<"DRAW"<<endl;
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
