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
// what we do is 
// we can not change the last element
// we make the previous element similiar to previous elements
// so at 1st starting from last elemtent we put a mirrir and make its previous elemenst similiar
// we count the similiar elements;
void solve(){
cin>>n;
vector<ll>v(n);
inp(v);
ll ct=0, x=v[n-1], i=n-1, ans=0;
while(i>=0){
    while(v[i]==x && i>=0){
        ct++;
        i--;
        // we count the emeiliar elements from last index
        // to put a mirror in a right postition and make the previous indexes equal
    }
    if(i<0) break;
    ans++;// how many times we put a mirror will be the ans;
    i-=ct;
    ct*=2;// since the similiar elements will be twice after we put the mirror
    // 234|555
    // 555555
}
cout<<ans<<endl;
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
//n=1;
cin>>n;
fr(i,n){
  cerr<<"Case #"<<i<<": ";
  solve();
}
return 0;
}