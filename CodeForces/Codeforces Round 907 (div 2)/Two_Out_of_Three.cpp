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
     map<ll,ll>mp;
     for(auto i:v) mp[i]++;
     if(mp.size()==1){
          cout<<-1<<endl;
          return;
     } 
     ll ct=0;
     for(auto [x,y]:mp){
          if(y>=2) ct++;
     }
     if(ct<=1){
          cout<<-1<<endl;
          return;
     }
     bool flag=0;
     for(auto &[x,y]:mp){
          if(y>=2){
               y=flag;
               flag=1;
          }else{
               y=3;
          }
          // cout<<x<<" "<<y<<endl;
     }
     int ct0=1,ct1=2;
     for(auto &i:v){
          // cout<<mp[i]<<" "<<ct0<<" /";
          if(mp[i]==0){
               i=ct0++;
               ct0=min(ct0,2);
          }
          else if(mp[i]==1){
               i=ct1;
               ct1++;
               ct1=min(ct1,3);
          }
          else if(mp[i]==3) {
               i=3;
          }
     }
     // cout<<endl;
     for(auto i:v){
          cout<<i<<" "; 
     }
     cout<<endl;

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