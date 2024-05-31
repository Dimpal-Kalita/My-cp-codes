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
     vector<vector<vl>>count(n,vector<vl>(n,vl(27,0)));
     vector<vector<stack<ll>>>st(n,vector<stack<ll>>(n));
     while(q--){
          ll t;
          cin>>t;
          if(t==0){
               char ch;
               cin>>ch;
               ll x,y;
               cin>>x>>y;
               count[x][y][ch-'a']++;
               st[x][y].push(ch-'a');
          }else if(t==1){
               ll x,y;
               cin>>x>>y;
               if(st[x][y].size()==0) continue;
               char ch=st[x][y].top()+'a';
               st[x][y].pop();
               count[x][y][ch-'a']--;
          }else{
               char ch;
               cin>>ch;
               ll x,y;
               cin>>x>>y;
               ll ct=count[x][y][ch-'a'];
               ll tot=st[x][y].size();
               // cout<<ct<<" "<<tot<<endl;
               if(2*ct>tot){
                    cout<<"yes"<<endl;
               }else{
                    cout<<"no"<<endl;
               }
          }
     }
}



int main()
{ 
    fast_io;
    
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   