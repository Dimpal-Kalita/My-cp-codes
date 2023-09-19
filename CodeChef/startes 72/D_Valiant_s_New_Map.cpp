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







bool maxsquare(vector<vector<ll>>&v,ll x, ll n, ll m){
    vector<vector<ll>> dp(n, vector<ll>(m,0));
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]>=x){
                dp[i][j]=1;
                if(i>0 && j>0){
                    dp[i][j]+=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                } 
                if(dp[i][j]==x) return 1;
            }
        }
    }
    return 0;
}

void dk(){
     ll n, m;
     cin>>n>>m;
     vector<vector<ll>> v(n, vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
    }
    ll ans=0;
    ll l=1, r=1e7;

    while(l<r){
        ll mid=(l+r)/2;
        if(maxsquare(v,mid,n,m)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid;
        }
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
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}