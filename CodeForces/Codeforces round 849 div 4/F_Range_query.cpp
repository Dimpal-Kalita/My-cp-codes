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
    void add(ll idx, ll val){
        for(;idx<=n; idx+=idx&-idx){
            bit[idx]+=val;
        }
    }
    void update(ll l,ll r){
       add(l,1);
       add(r+1, -1);
    }
    int point_query(int idx) {
        int ret = 0;
        for (;idx;idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

};

ll calc(ll n){
    ll sum = 0;
    while(n){
        sum=sum+n%10;
        n=n/10;
    }
    return sum;
}

void dk(){
     ll n,q;
     cin>>n>>q;
     vector<ll> v(n+1);
     for(int i=1;i<=n;i++){
        cin>>v[i];
     }
     BIT bt(n);
     map<int,int>mp;
     while(q--){
        ll x;
        cin>>x;
        if(x==1){
            ll l, r;
            cin>>l>>r;
            bt.update(l, r);
        }
        else{
            ll ind;
            cin>>ind;
            ll val=bt.point_query(ind);
            val= min(val, 5ll);
            val-=mp[ind];
            while(val>0){
                v[ind]=calc(v[ind]);
                val--;
                mp[ind]++;
            }
            cout<<v[ind]<<endl;
        }
     } 
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}