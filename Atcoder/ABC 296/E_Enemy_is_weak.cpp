// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

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


struct BIT{
    vector<ll> bit;
    ll n;
    BIT(ll n){
        this->n=n;
        bit.assign(n+1,0);
    }

    ll sum(ll r){
        ll ret=0;
        for(;r>=0;r=(r&(r+1))-1){
            ret+=bit[r];
        }
        return ret;
    }

    ll sum(ll l,ll r){
        return sum(r)-sum(l-1);
    }

    void add(ll idx,ll delta){
        for(;idx<n;idx=idx|(idx+1)){
            bit[idx]+=delta;
        }
    }
};

void dk(){
     ll n;
     cin>>n;
     vector<ll> v(n);
     map<ll,ll> mp;
     ll mx=0;
     for(auto &it:v){
        cin>>it;
        mp[it]++;
     }
     ll ct=0;
     for(auto &it:mp){
        it.S=ct++;
     }
     for(auto &it:v){
        it=mp[it];
        mx=max(mx,it);
     }
     reverse(all(v));
     ll ans=0;
     BIT bit1(mx+1), bit2(mx+1);

     for(int i=0;i<n;i++){
        ll x=v[i];
        ans+=bit1.sum(x);
        ll val=bit2.sum(x);
        bit1.add(x,val);
        bit2.add(x,1);
     }

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