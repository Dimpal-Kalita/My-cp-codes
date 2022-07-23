#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%ll",x)
#define md                  10000007
#define pb                  push_back
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,k,n)            for(ll i=k;i<n;i++)
#define dsort(a)            sort(a,a+n,greater<int>())
#define pn                  printf("\n")
#define debug               printf("I am here\n")
#define ps                  printf(" ")
/*ll FastPow(ll a, ll n, ll MOD){ if(n==0LL) return 1LL; 
if(n%2==1)return (a*FastPow(a,n-1,MOD))%MOD;
ll temp=FastPow(a,n/2,MOD);
return (temp*temp)%MOD; }*/
//ll find_all_divisor(ll n){  fr1(i,sqrt(n)){     ll i,x;  if(n % i == 0)  { x = n / i; v.pb(i);  if(i != x) v.pb(x);}}}
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
}*/ll m,n,p,x,y;
vector<ll> edges[1000005];
vector<ll> v1, v2;
bool vis[500005];
ll ar[1000005];
ll br[1000005];
ll cr[1000005];
void solve(){
  cin>>n>>m;
  v1.resize(n);
  v2.resize(m);
  ll sum=0;
  map<ll,ll> m1, m2;
  for(auto &x: v1) {
  cin>>x;
  m1[x]++;
  }
  for(auto &x: v2) {
  cin>>x;
  m2[x]++;
  }
  x=0,y=0;
  while(x<n && y<m){
      if(v1[x]==v2[y]){
          ll k=v1[x];
          sum+=m1[k]*m2[k];
          x+=m1[k];
          y+=m2[k];

      }
      else if(v1[x]<v2[y]) x++;
      else y++;
  }

  cout<<sum<<endl;
  return;
 }


int main()
{  
ll t;
t=1;
while(t--){
solve();
}
 return 0;
}