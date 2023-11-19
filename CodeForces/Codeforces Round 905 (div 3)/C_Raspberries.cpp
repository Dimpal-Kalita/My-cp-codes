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
     ll n,k;
     cin>>n>>k;
     vl v(n);
     inp(v);

     if(k==4){
          ll ct=1e9;
          map<ll,ll>mp;
          for(auto i:v){
               ll cur=i;
               mp[i]++;
               while(cur%k) cur++;
               ct=min(ct,cur-i);
          }
          for(int i=1;i<=10;i++){
               map<ll,ll>mp1=mp;
               mp1[i]--;
               if(mp1[i]>=0){
                    for(int j=1;j<=10;j++){
                         mp1[j]--;
                         ll cur1=i,cur2=j;
                         if(mp1[j]>=0){
                              while(cur1%2) cur1++;
                              while(cur2%2) cur2++;
                              ct=min(ct,cur1-i+cur2-j);
                         }

                    }
               }
          }
          cout<<ct<<endl;          
     }else{
          ll ct=1e9;
          for(auto i:v){
               ll cur=i;
               while(cur%k) cur++;
               ct=min(ct,cur-i);
          }
          cout<<ct<<endl;
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