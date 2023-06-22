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




void dk(){
     ll n,k;
     cin>>n>>k;
     vector<ll>cnt(1e6+1,0),notcnt(1e6+1,0); 
     set<ll>st;
     rep(i,0,n){
          ll x;
          cin>>x;
          if(k%x==0){
              st.insert(x);
              notcnt[x]++;
          }
     }
     ll ans=0;
     for(auto val:st){

          cnt[val]+=notcnt[val];
          ll x=k/val;

          for(ll i=1;i*i<=x;i++){
               if(x%i==0){
                    ll ff=i, ss=x/i;
                    ll tt=0;
                    if(ff==ss and ss==val){
                         ll ct= cnt[ff];
                         tt+= (ct*(ct-1)*(ct-2))/6;
                    }
                    else if(ff==ss){
                         ll ct=cnt[ff];
                         tt+= (ct*(ct-1))/2 * cnt[val];
                    }else if(ff==val){
                         ll ct=cnt[ff];
                         tt+= (ct*(ct-1))/2 * cnt[ss];
                    }
                    else if(ss==val){
                         ll ct=cnt[ss];
                         tt+= (ct*(ct-1))/2 * cnt[ff];
                    }
                    else{
                         tt+= cnt[ff]*cnt[ss]*cnt[val];
                    }
                    ans+=tt;
               }
          }
     }
     // debug(v);
     cout<<ans<<endl;
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