/**
 * 
 * author: Dimpal Kalita
 * date: 21/05/2023 17:27:39
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds2; // find_by_order, order_of_key

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



vector<ll>compress(vector<ll> v){
     vector<ll> ans;
     map<ll,ll> mp;
     for(auto x:v) mp[x]=0;
     ll cnt=0;
     for(auto &x:mp) x.S=cnt++;
     for(auto x:v) ans.pb(mp[x]);
     return ans;
}

void dk(){
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);
     v=compress(v);
     map<ll,ll> mp,cnt;
     pbds A;
     for(int i=0;i<n;i++){
          cnt[i]=A.order_of_key(v[i])+mp[v[i]];
          A.insert(v[i]);
          mp[v[i]]++;
     }

     mp.clear();
     pbds2 B;
     ll ans=0,x=0;
     for(int i=n-1;i>=0;i--){
          ans+= cnt[i]*(B.order_of_key(v[i])+mp[v[i]]);
          // cout<<cnt[i]<<" "<<B.order_of_key(v[i])+mp[v[i]]<<endl;
          B.insert(v[i]);
          mp[v[i]]++;
     }

     A.clear();
     B.clear();
     mp.clear();
     for(int i=n-1;i>=0;i--){
          cnt[i]=A.order_of_key(v[i])+mp[v[i]];
          A.insert(v[i]);
          mp[v[i]]++;
     }

     mp.clear();
     for(int i=0;i<n;i++){
          ans+= cnt[i]*(B.order_of_key(v[i])+mp[v[i]]);
          B.insert(v[i]);
          mp[v[i]]++;
     }

     for(auto [x,y]:mp){
          ans-=( y*(y-1)*(y-2))/6;
     }
     cout<<ans<<endl;
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