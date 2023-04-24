/**
 * 
 * author: Dimpal Kalita
 * date: 23/04/2023 16:28:21
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


void dk(){
      ll n;
      cin>>n;
      vl v(2*n);
      inp(v);

      sort(all(v));



     for(int _=0;_<2*n-1;_++){

        vector<pll> ans;
        ll sum=v[2*n-1];
        vector<ll> vis(2*n,0);
        map<ll,ll> mp;
        ans.pb({sum,v[_]});
        vis[_]=1;
        vis[2*n-1]=1;

        for(int i=2*n-2;i>=0;i--){

            if(vis[i]) continue;

            ll mx= v[i],flag=0;

            vis[i]=1;

            ll ind=0;
            if(mp.count(sum-mx)) ind= mp[sum-mx]+1;
            else ind= lower_bound(v.begin(), v.end(),sum-mx)-v.begin();
            
            if(ind<2*n && v[ind]==sum-mx && !vis[ind]){
                mp[sum-mx]=ind;
                ans.pb({mx,v[ind]});
                vis[ind]=1;
                sum=mx;

            }else{
                break;
            }
        }

        if(ans.size()==n){
            cout<<"YES"<<endl;
            cout<<ans[0].F+ans[0].S<<endl;

            for(auto it:ans){
                cout<<it.F<<" "<<it.S<<endl;
            }
            return;
        }

      }

      cout<<"NO"<<endl;
      return;

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