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




void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     ll sum=accumulate(all(v),0ll);
     auto check=[&](ll x){
          vector<pll>ps(n+1),ss(n+1);
          ll pipe=0,cur=0;
          for(int i=0;i<n;i++){
               if(cur+v[i]>x){
                    pipe+=v[i];
                    cur=0;
               }else{
                    cur+=v[i];
               }
               ps[i+1]={pipe,cur};
          }
          pipe=0,cur=0;
          for(int i=n-1;i>=0;i--){
               if(cur+v[i]>x){
                    pipe+=v[i];
                    cur=0;
               }else{
                    cur+=v[i];
               }
               ss[i]={pipe,cur};
          }
          // debug(ps);
          // debug(ss);
          for(int i=0;i<n;i++){
               if(ps[i+1].F+ss[i+1].F<=x and ps[i+1].S+ss[i+1].S<=x) return true;
          }
          for(int i=0;i<n;i++){
               if(ps[i].F+ss[i].F<=x and ps[i].S+ss[i].S<=x) return true;
          }
          return false;
     };
     ll l=*max_element(all(v)),r=sum+1;
     while(l<r){
          ll mid=(l+r)/2;
          if(check(mid)){
               r=mid;
          }else{
               l=mid+1;
          }
     }
     cout<<r<<endl;
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