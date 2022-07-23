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
ll m,n,p,x,y;
vector<ll> edges[1000005];
bool vis[500005];
void solve(){
    string s;
    cin>>s;
    n=s.length();
    x=0,y=0;
    vector<ll> dp1(n+1, 0), dp2(n+1,0);
    set<ll> set[32];
    fr1(i,1,n+1){
            set[s[i]-'a'].insert(i);
    }
    fr1(i,1,n+1){
        dp2[i]=max(dp2[i-1], dp1[i]);
        auto it = set[s[i]-'a'].upper_bound(i);
        if(it==set[s[i]-'a'].end()) continue;
        ll k =*it;
        dp1[k]= max(dp1[k], dp2[i-1]+1);
    }
   ll ans=0;
   fr1(i,1,n+1){
       ans=max(ans, dp1[i]);
   }
   cout<<n-(2*ans)<<endl;
}

int main()
{ 
ll t;
//t=1;
cin>>t;
while(t--){
  solve();
}
return 0;
}