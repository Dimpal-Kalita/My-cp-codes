// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define sz(x)               ((long long)((x).size()));
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


ll n, k, m;


map<pll,ll>mp;
map<pll,ll> temp;

ll recur(ll ind, ll ignore, ll sum){


    if(ind==n){
        if(ignore==-1) return 0;
        // cout<<sum<<" "<<ignore<<endl;

        if((sum-ignore)%k==ignore){
            return 1;
        }

        return 0;
    }
    // if(temp.count({ignore,sum})) return 0;
    if(mp.count({ignore,sum})) return mp[{ignore, sum}];

    ll ans=0;
    if(ignore==-1){

        for(int i=0;i<k;i++){
            ans= (ans+recur(ind+1, i, sum))%m;
            ans= (ans+recur(ind+1, -1, sum+i))%m;
        }

        return ans;
    }


    for(int i=0;i<k;i++){
        ans= (ans+recur(ind+1, ignore, sum+i))%m;
    }
    // temp[{ignore,sum}]=1;

    return mp[{ignore,sum}]=ans;
}


void dk(){
      cin>>n>>k>>m;
    //   string s="";
      ll ans=recur(0,-1,0);
      cout<<ans<<endl;
}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}