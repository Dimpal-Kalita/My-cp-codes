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
     ll n;
     cin>>n; 
     vector<vl>v;
     for(int i=0;i<n;i++){
          ll x,y,a,b;
          cin>>x>>y>>a>>b;
          v.pb({x,y,b});
     }
     sort(all(v));
     ll seg=1;
     ll begin=v[0][0];
     ll end=v[0][1];
     map<ll,ll>mp;
     ll mx=v[0][2];
     map<ll,pll>mp2;
     mp2[0]={0,0};
     mp2[seg]={begin,end};
     mp[seg]=v[0][2];

     for(int i=0;i<n;i++){
          if(v[i][0]<=mx){
               mx=max(mx,v[i][2]);
               mp[seg]=max(mp[seg],v[i][2]);
               end=max(end,v[i][1]);
               mp2[seg]={begin,end};
          }else{
               mx=v[i][2];
               seg++;
               mp[seg]=v[i][2];
               begin=v[i][0];
               end=v[i][1];
               mp2[seg]={begin,end};
          }
     }
     // debug(v);
     // debug(mp);
     // debug(mp2);
     vector<ll>l,r;
     map<pll,ll>mp3;
     for(auto i:mp2){
          l.pb(i.S.F);
          r.pb(i.S.S);
          mp3[i.S]=i.F;
     }


     ll q;
     cin>>q;
     while(q--){
          ll x;
          cin>>x;
          ll ans=x;
          ll ind=upper_bound(all(l),x)-l.begin();
          ind--;
          if(x<=r[ind]){
               ans=max(ans,mp[mp3[{l[ind],r[ind]}]]);
          }
          cout<<ans<<" ";
     }
     cout<<endl;
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