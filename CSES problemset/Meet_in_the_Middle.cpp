// 2112048
// Dimpal Kalita
// CSE sec A

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






void dk(){
    ll n, s;
    cin>>n>>s;
    vector<ll> v(n);
    inp(v);
    vector<ll> sub1, sub2;

    auto subset_sum= [&](ll l, ll r)->vector<ll>{
        ll sz= r-l+1;
        vector<ll> req;

        for(ll i=0;i<(1<<sz); i++){
            ll sum=0;
            for(ll j=0;j<sz; j++){
                if(i&(1<<j)) sum+= v[l+j];
            }
        req.pb(sum);
        }
        return req;
    };

    sub1= subset_sum(0, n/2-1);
    sub2= subset_sum(n/2, n-1);

    sort(all(sub2));

    ll ans=0;


    for(auto i: sub1){
        ll req= s-i;
        ll dx= upper_bound(all(sub2), req)-lower_bound(all(sub2), req);
        ans+=dx;
    }

    cout<<ans<<endl;

}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}