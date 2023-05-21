/**
 * 
 * author: Dimpal Kalita
 * date: 29/04/2023 17:35:11
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


vector<vector<char>> rotate(ll n, ll m, vector<vector<char>> v, ll s, ll t){
     vector<vector<char>> ans(n, vector<char>(m));
     rep(i,0,n){
          rep(j,0,m){
               ans[i][j]=v[(i+s)%n][(j+t)%m];
          }
     }
     return ans;
}

void dk(){
      ll h,w;
      cin>>h>>w;
      ll ct1=0, ct2=0;
      vector<vector<char>> v(h, vector<char>(w)), v2(h, vector<char>(w));
      rep(i,0,h){
          rep(j,0,w){
              char c;
              cin>>c;
              v[i][j]=c;
          }
      }
      rep(i,0,h){
          rep(j,0,w){
              char c;
              cin>>c;
              v2[i][j]=c;
          }
      }
      
      for(int i=1;i<=h;i++){
          for(int j=1;j<=w;j++){
              vector<vector<char>> v3=rotate(h,w,v,i,j);
                 if(v3==v2){
                      cout<<"Yes"<<endl;
                      return;
                 }
          }
      }
      cout<<"No"<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}