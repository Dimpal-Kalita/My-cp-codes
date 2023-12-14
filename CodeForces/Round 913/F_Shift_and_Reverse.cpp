#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;






/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(long long t) {cerr << t;}
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/



ll solve(vl v){
     ll n=v.size();
     vl ps(n+1);
     for(int i=0;i<n;i++){
          ps[i]=ps[(i-1+n)%n];
          if(v[i]<v[(i-1+n)%n]) ps[i]++;
     }
     debug(ps);
     ll ans=1e18;
     for(ll i=0;i<n-1;i++){
          ll x=ps[i];
          ll y=ps[n-1]-ps[i+1];
          if(x==0 and y==0){
               ans=min({ans,n-i-1,i+3});
          }
     }
     return ans;
}

ll rev_solve(vl v){
     ll n=v.size();
     vl ps(n+1);
     if(is_sorted(all(v))) return 0;

     for(int i=0;i<n;i++){
          ps[i]=ps[(i-1+n)%n];
          if(v[i]<v[(i-1+n)%n]) ps[i]++;
     }
     debug(ps);
     ll ans=1e18;
     for(ll i=0;i<n-1;i++){
          ll x=ps[i];
          ll y=ps[n-1]-ps[i+1];
          if(x==0 and y==0){
               ans=min({ans,n-i-1,i+1});
          }
     }
     return ans;
}


void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);

     if(is_sorted(all(v))){
          cout<<0<<endl;
          return;
     }
     ll x=solve(v);
     ll y=rev_solve(vl(v.rbegin(),v.rend()));
     if(min(x,y+1)==1e18){
          cout<<-1<<endl;
          return;
     }
     cout<<min(x,y+1)<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   