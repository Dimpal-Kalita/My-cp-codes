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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
     tree_order_statistics_node_update>;


void dk(){
      ll n;
      cin>>n;
      vl v(n);
      inp(v);
      vl ps(n+1,0),ss(n+1);
      rep(i,0,n){
          ps[i+1]=ps[i]+max(0LL,v[i]);
          if(i%2==0){
               ss[i+1]=ss[i]+max(0LL,v[i]);
          }else{
               ss[i+1]=ss[i];
          }
      }
      ll mx=ps[n],ans=0;
      rep(i,0,n){
          ll val=ss[i]+mx-ps[i+1];
          if(i%2){
               ans=max(ans,val);
          }else{
               ans=max(ans,val+v[i]);
          }
      }
      cout<<max(ans,ss[n])<<endl;
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