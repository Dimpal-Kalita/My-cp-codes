/**
 * 
 * author: Dimpal Kalita
 * date: 14/06/2023 12:08:29
 * 
 */

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
      ll n,m;
      cin>>n>>m;
      vl v(n);
      inp(v);
      sort(all(v));

      vector<ll> pre(n), suf(n);

      for(int i=1;i<n;i++){
          pre[i]= pre[i-1]+ (v[i]-v[i-1])*i;
      }
     //  debug(pre);
      for(int i=n-2;i>=0;i--){
          suf[i]= suf[i+1]+ (v[i+1]-v[i])*(n-i-1);
      }
     //  debug(suf);
      vl tot(n);
      for(int i=0;i<n;i++){
          tot[i]= pre[i]+ suf[i];
      }
      rep(tt,0,m){
          ll x;
          cin>>x;
          ll ind= lower_bound(all(v),x)-v.begin();
          if(ind<n and ind>=0 and v[ind]==x){
               cout<<tot[ind]<<" ";
               continue;
          }
          ll y=ind-1;
          if(y==n-1){
               cout<<(x-v[y])*n+tot[y]<<" ";
               continue;
          }

          if(ind==0){
               cout<<(v[0]-x)*n+tot[0]<<" ";
               continue;
          }

          ll left=v[ind-1], right=v[ind];
          cout<<(x-left)*(ind)+(right-x)*(n-ind)+pre[y]+suf[ind]<<" ";
      }

}



int main()
{ 
    fast_io;
  
    int n=1;
//     cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}