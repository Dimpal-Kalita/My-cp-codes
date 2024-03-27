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
     ll n,m;
     cin>>n>>m;
     vector<pair<ll,string>>v(n);
     rep(i,0,n){
          string s;
          cin>>s;
          reverse(all(s));
          ll ct=0;
          for(auto it:s){
               if(it=='0') ct++;
               else break;
          }
          reverse(all(s));
          v[i]={ct,s};
     }
     sort(all(v),greater<pair<ll,string>>());
     ll sum=0;
     rep(i,0,n){
          if(i%2==0){
               sum+=(v[i].S.length()-v[i].F);
          }else{
               sum+=v[i].S.length();
          }
     }
     if(sum>m){
          cout<<"Sasha"<<endl;
          return;
     }
     cout<<"Anna"<<endl;
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