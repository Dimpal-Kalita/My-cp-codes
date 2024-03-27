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

#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif





map<ll,set<pll>>tree;

void update(int l,int r,int s,int e,int id,pair<ll,ll>val,int type){ 
     if(s>=r || e<=l) return;
     if(s>=l && e<=r){
          if(type==1){
               tree[id].insert(val);
          }else{
               tree[id].erase(tree[id].find(val));
          }
          return;
     }
     int mid=(s+e)/2;
     update(l,r,s,mid,2*id,val,type);
     update(l,r,mid,e,2*id+1,val,type);
}

ll query(int l,int r,int s,int e,int id){
     if(s>=r || e<=l) return 0;
     if(s>=l && e<=r){
          if(tree[id].empty()) return 0;
          return tree[id].rbegin()->first;
     }
     ll ans=0;
     if(tree[id].size()) ans=tree[id].rbegin()->first;
     ll mid=(s+e)/2;
     return max({ans,query(l,r,s,mid,2*id),query(l,r,mid,e,2*id+1)});
}

void dk(){
     ll n;
     cin>>n;
     
     rep(i,0,n){
          int x;
          cin>>x;
          update(i+1,i+2,0,n+1,1,{x,0},1);
     }

     map<ll,array<ll,3>>mp;
     
     ll q;
     cin>>q;
     rep(i,0,q){
          ll t;
          cin>>t;
          if(t==1){
               ll l,r,x;
               cin>>l>>r>>x;
               mp[i+1]={l,r,x};
               update(l,r+1,0,n+1,1,{x,i+1},1);
          }
          if(t==2){
               ll ind;
               cin>>ind;
               ll l=mp[ind][0],r=mp[ind][1],x=mp[ind][2];
               update(l,r+1,0,n+1,1,{x,ind},2);
          }
          if(t==3){
               ll ind;
               cin>>ind;
               cout<<query(ind,ind+1,0,n+1,1)<<endl;
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