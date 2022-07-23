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
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
/*ll FastPow(ll a, ll n, ll MOD){ if(n==0LL) return 1LL; 
if(n%2==1)return (a*FastPow(a,n-1,MOD))%MOD;
ll temp=FastPow(a,n/2,MOD);
return (temp*temp)%MOD; }*/
/*vector<ll> primeFactors(ll n)
{vector<ll> v;
while (n % 2 == 0)
{
v.pb(2);
n = n/2;
}
 for (ll i = 3; i <= sqrt(n); i = i + 2)
 {
while (n % i == 0)
{
 v.pb(i);
    n = n/i;
    }
}
if (n > 2)
v.pb(n);
return v;
}*/
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
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}*/
/*string toString(ll x) {
    //code to convert no to binary string
    string ans;
    while(x) {
        ans += '0' + (x & 1) ;
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}*/
ll p(ll n, ll k, vector<vector<ll>> &dp){
    if(n<k) return 0;
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    if(k==n){
        dp[n][k]= n;
        return dp[n][k];
    }
    if(k==0){
        dp[n][k]=1;
        return dp[n][k];
    }
    return k*p(n-1,k-1,dp) + p(n-1,k,dp);
}
ll m,n,x,y,k;
void solve(){
    cin>>n>>k;
    vector<vector<ll>> dp(n+1, vector<ll>(k+1,-1));
    x= p(n,k,dp);
    cout<<x<<endl;
return;
}
int main()
{ 
fast_io;
#ifndef ONLINE_JUDGE
file_io;
#endif
ll n;
//n=1;
cin>>n;
for(ll i=1;i<=n;i++){
  cerr<<"Case #"<<i<<": ";
  solve();
}
return 0;
}