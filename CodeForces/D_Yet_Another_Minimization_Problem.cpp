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


// by calculation
// the formmula reduces to (summation  a_i)^2 + (n-2) * summation a_i^2;
// second part of the equation will remain same even after swap as it involves only 
// one term square then sum.. but in first part if value is swapped 
// summation will reduce reducing the value of the square also

vector<ll> a, b;
ll calc(ll ind, ll sum1,ll sum2, map<pll,ll> &dp){
    ll one= sum1*sum1+ sum2*sum2;

    if(ind<0) return one;

    if(dp.count({ind, one})!=0) return dp[{ind, one}];
    
    ll x=calc(ind-1, sum1, sum2,dp);
    ll y=calc(ind-1, sum1+b[ind]-a[ind], sum2+a[ind]-b[ind], dp);

    return dp[{ind, one}]= min(one,min(x, y));
}




void dk(){
    ll n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    map<pll,ll>dp;
    
    inp(a);
    inp(b);
    ll sum1=accumulate(all(a), 0ll);
    ll sum2= accumulate(all(b), 0ll);
    ll ans= 0;
    for(int i=0;i<n;i++){
       ans+= (n-2) * a[i] * a[i]; 
    }
    for(int i=0;i<n;i++){
       ans+= (n-2) * b[i] * b[i];
    }
    //cout<<ans<<" ";
    ans+= calc(n-1, sum1, sum2, dp);
    
    ans= max(0ll, ans);
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
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}