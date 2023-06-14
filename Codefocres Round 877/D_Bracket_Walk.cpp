/**
 * 
 * author: Dimpal Kalita
* 
 */

#include<bits/stdc++.h>
#include<atcoder/segtree.hpp>
using namespace std;
using namespace atcoder;

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


vector<vl> generate(vl v){
     ll n=v.size();
     vector<vector<int>>ans;
     for(int i=0;i<(1<<n);i++){
          vector<int>temp;
          for(int j=0;j<n;j++){
               if(i&(1<<j)){
                    temp.push_back(v[j]);
               }
          }
          ans.push_back(temp);
     }
}

typedef struct node{
    ll open, close, ans;
} node;
 
node op(node a, node b) {
    ll ans= a.ans+ b.ans+ 2*min(a.open,b.close);
    ll open = a.open + b.open;
    ll close = a.close + b.close;
    return {open, close, ans};
}
node e(){return {0, 0};}


void dk(){
     ll n,q;
     cin>>n>>q;
     string s;
     cin>>s;
     vector<node>v(n);
     rep(i,0,n){
        if(s[i]=='(') v[i].open=1;
        else v[i].close=1;
        // cout<<v[i].close<<" ";
    }

     segtree<node, op, e> seg(v);

     while(q--){
          ll x;
          cin>>x;
          if(seg.get(x-1).open==1){
               seg.set(x-1, {0,1});
          }else{
               seg.set(x-1, {1,0});
          }
          node ans=seg.all_prod();
          cout<<ans.open<<" "<<ans.close<<endl;
          if((ans.close-ans.open)<=2){
               cout<<"YES"<<endl;
          }
          else{
               cout<<"NO"<<endl;
          }
          
     }      

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