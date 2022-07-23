#include<bits/stdc++.h>
using namespace std;


#define ll                  long long
#define md                  1000000007
#define pb                  push_back
#define mp                  make_pair
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define re(v,n)             v.resize(n)
#define inp(v)              for(auto &x: v) cin>>x           
#define dsort(a)            sort(a,a+n,greater<int>())
#define debug               printf("I am here\n")
/*ll FastPow(ll a, ll n, ll MOD){ if(n==0LL) return 1LL; 
if(n%2==1)return (a*FastPow(a,n-1,MOD))%MOD;
ll temp=FastPow(a,n/2,MOD);
return (temp*temp)%MOD; }*/
//ll find_all_divisor(ll n){  fr(i,sqrt(n)){     ll i,x;  if(n % i == 0)  { x = n / i; v.pb(i);  if(i != x) v.pb(x);}}}
/*bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
        for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}*/
/*bool sortsec(const pair<pair<int,int>,int> &a,
              const pair<pair<int,int>,int> &b)
{
    return (a.first.first < b.first.first);
}*/
/*bool sortbysec(const pair<pair<int,int>,int> &a,
              const pair<pair<int,int>,int> &b)
{
    return (a.first.second < b.first.second);
}*/

// think about what will be the indexes
// think the recursive soluiton
// store the nodes in a dp array for memaztion
// thats how this is solved
// TlE will be there without memoaziation

ll m,n,k,p,x,y;
vector<ll> edges[1000005];
bool vis[500005];
ll jumped(vector<ll> &vp, vector<ll> &dp,ll n,ll k){
 if(n==0) return 0;
 if(dp[n]!=-1) return dp[n];
 ll minimum=INT_MAX ;
 for(ll i=1;i<=k;i++){
   if(n-i>=0) minimum=min(minimum, jumped(vp,dp,n-i,k)+abs(vp[n]-vp[n-i]));
 }
 return dp[n]=minimum;
}
void solve(){
cin>>n>>k;
vector<ll> vp(n), dp(n+1,-1);
inp(vp);
cout<<jumped(vp, dp,n-1,k)<<endl;
return;
}
int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
ll n;
n=1;
//cin>>n;
fr(i,n){
  cerr<<"Case #"<<i+1<<": ";
  solve();
}
return 0;
}