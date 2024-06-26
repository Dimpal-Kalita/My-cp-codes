/**
 * 
 * author: Dimpal Kalita
 * date: 24/04/2023 21:14:13
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
      string s;
      cin>>s;
      if(n%2){
          cout<<-1<<endl;
          return;
      }

      priority_queue<pll> pq;
      map<ll,ll> mp;
      for(int i=0;i<n/2;i++){
          if(s[i]==s[n-i-1]){
               mp[s[i]]++;
          }
      }
      debug(mp);

      for(auto it:mp){
          pq.push({it.S,it.F});
      }

      ll ans=0;

      while(pq.size()>1){
          pll x= pq.top();
          pq.pop();
          pll y= pq.top();
          pq.pop();

         x.F-=1;
         y.F-=1;
         ans+=1;
         if(y.F!=0){
          pq.push({y.F,y.S});
         }
         if(x.F!=0){
          pq.push({x.F,x.S});
         }
      }

      if(pq.size()==0){
          cout<<ans<<endl;
          return;
      }

      pll x= pq.top();
      ll val= 2*x.F;
      ll cnt=0;
      for(int i=0;i<n/2;i++){
          if(s[i]==x.S and s[i]!=s[n-i-1]){
               cnt++;
          }
          else if(s[n-i-1]==x.S and s[i]!=s[n-i-1]){
               cnt++;
          }
      }

      ll tt= n/2;
      tt-=(mp[x.S]-x.F)*2;
      tt-=x.F;
      tt-= cnt;

      if(tt>=x.F){
          cout<<ans+x.F<<endl;
          return;
      }
      cout<<-1<<endl;
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