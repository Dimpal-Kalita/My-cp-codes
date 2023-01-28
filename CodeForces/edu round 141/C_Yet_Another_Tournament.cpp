// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



bool check(vector<pll>&vp, ll mid, ll m){
    ll n= vp.size();
    ll sum=0, ct=0;
    mid--;

    for(int i=0;i<n;i++){

        if(vp[i].S==mid){
            sum+=vp[i].F;
            ct++;
        }

    }
    if(sum>m) return 0;

    for(int i=0;i<n;i++){

        if(vp[i].S!=mid && sum+vp[i].F<=m){
            sum+=vp[i].F;
            ct++;
        }

    }

    return ct>=mid;
}

void dk(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    inp(v);
    vector<pll> vp;
    for(int i=0;i<n;i++){
        vp.pb({v[i],i});
    }
    sort(all(vp));

    ll l=0,r=n+1;
    ll ans=0;
    // ll x= check(vp,n,m);
    // cout<<x<<" ";
    while(l<r){
        ll mid= (l+r)/2;
        if(check(vp,mid,m)){
            // cout<<ans<<" ";
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid;
        }
    }

    cout<<min(max(n-ans+1, 0ll), n+1)<<endl;

}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}