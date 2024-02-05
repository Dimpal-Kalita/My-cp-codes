/**
 * 
 * author: Dimpal Kalita
 * date: 31/01/2024 21:15:13
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
      ll n,q;
      cin>>n>>q;
      string s;
      cin>>s;
      ll cur=0,mx=0;
      char last='$';
      for(auto &i:s){
          if(i==last) cur++;
          else{
               cur=1;
          }
          last=i;
          mx=max(mx,cur);
      }
      cout<<mx<<" ";
      rep(i,0,q){
          char ch;
          cin>>ch;
          if(ch==last){
               cur++;
          }else{
               cur=1;
          }
          mx=max(mx,cur);
          cout<<mx<<" ";
          last=ch;
      }
      cout<<endl;
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