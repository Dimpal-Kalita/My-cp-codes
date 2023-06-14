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




ll find_mex(map<ll,ll>st){
     ll mex=0;
     while(st.count(mex)) mex++;
     return mex;
}


void dk(){
     ll n;
     cin>>n;
     vector<pll>v(n);
     rep(i,0,n) cin>>v[i].F;
     rep(i,0,n) cin>>v[i].S;
    
     map<ll,ll>st;
     for(auto it:v){
          st[it.F]++;
          st[it.S]++;
     }

     ll ans=find_mex(st);
     map<ll,ll> mp=st;     
     if(n%2){
          cout<<find_mex(st)<<endl;
          return;
     }

     priority_queue<ll> pq1,pq2;
     ll temp=0;


     for(int i=1;i<n-1;i++){
          if(i%2==0){
               pq1.push(v[i].F);
          }else{
               pq2.push(v[i].S);
          }
     }

     
     for(int i=0;i<n;i++){

          if(i%2==0){
               if(mp[v[i].S]==1){
                    if(v[i].S<=ans){
                         temp=max(temp,v[i].S);
                    }else{
                        cout<<ans<<endl;
                        return;
                    }
               }else{
                    cout<<ans<<endl;
                    return;
               }
          }
          else{
               if(mp[v[i].F]==1){
                    if(v[i].F<=ans){
                         temp=max(temp,v[i].F);
                    }else{
                        cout<<ans<<endl;
                        return;
                    }
               }else{
                    cout<<ans<<endl;
                    return;
               }
          }
     }
     cout<<temp<<endl;
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