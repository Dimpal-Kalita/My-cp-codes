#include<bits/stdc++.h>
using namespace std;


#define md                  1000000007
#define pb                  push_back
#define mp                  make_pair
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define inp(v)              for(auto &x: v) cin>>x   
#define all(x)              (x).begin(), (x).end()        
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);

/*--------------------------------------------Debug Starts-----------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fs); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------Debug Complete-----------------------------------------------------------------------*/
 

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
//ll m,n,p,x,y;
void solve(){
 
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