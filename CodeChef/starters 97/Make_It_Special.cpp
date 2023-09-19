/**
 * 
 * author: Dimpal Kalita
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




bool isSpecialPermutation(vl v){
     sort(all(v));
     for(int i=1;i<v.size();i++){
          v[i]-=v[0];
     }
     v[0]=0;
     for(int i=1;i<v.size();i++){
          if(v[i]!=i) return false;
     }
     return true;
}

bool isPowerOfTwo(ll n){
     return (n && !(n & (n - 1)));
}

void dk(){
     ll n,q;
     cin>>n>>q;
     while(q--){
          ll L,R;
          cin>>L>>R;
          // ll ct=0;
          // for(int x=L;x<=R;x++){
          //      vl v;
          //      for(int i=1;i<=n;i++){
          //           v.pb(x^i);
          //      }
          //      // debug(v);
          //      if(isSpecialPermutation(v)){
          //           cerr<<x<<" ";
          //           ct++;
          //      }
          // }
          // cerr<<endl;
          // cout<<ct<<endl;

          ll ans=0,x=63;
          ll l=L+1,r=R+1;
          for(;x>=0;x--){
               if((n&(1LL<<x))) break;
          }
          ll low=0,high=0;
          for(ll i=x+1;i<64;i++){
               if((r&(1LL<<i))) high|=1LL<<(i-x-1);
               if((l&(1LL<<i))) low|=1LL<<(i-x-1);
          }
          cerr<<high<<" "<<low<<endl;
          ans=high-low;
          ans=2*ans;
          if(isPowerOfTwo(r) and ans>0) ans--;
          if(L%(1ll<<x)==0) ans++;
          cout<<ans<<endl;
     } 

}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}