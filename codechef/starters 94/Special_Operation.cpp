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
      ll n,m;
      cin>>n>>m;

      vector<vl> v(n,vl(m,0));
      vl cnt(30,0);

      rep(i,0,n){
          rep(j,0,m){
               cin>>v[i][j];

               for(ll k=0;k<30;k++){
                    if((v[i][j]&(1ll<<k))){
                         cnt[k]++;
                    }
               }

          }
      }

      vector<vl>row(n,vl(30,0)), col(m, vl(30,0));

      
      rep(i,0,n){
          
          rep(j,0,m){

               for(ll k=0;k<30;k++){
                    if((v[i][j]&(1ll<<k))){
                         row[i][k]++;
                         col[j][k]++;
                    }
               }

          }
      }


      ll ans=0;


      rep(i,0,n){
          rep(j,0,m){
               vl set=cnt;
               vl notset(30,0);
               rep(k,0,30){
                    notset[k]= n*m-set[k];
               }
               rep(k,0,30){
                    set[k]-=row[i][k];
                    set[k]-=col[j][k];
                    notset[k]-=(n-row[i][k]);
                    notset[k]-=(m-col[j][k]);

                    if((v[i][j]&(1ll<<k))){
                         set[k]++;
                    }else{
                         notset[k]++;
                    }

               }

               ll val=0;
               rep(k,0,30){
                    if((v[i][j]&(1ll<<k))){
                         val+= notset[k]*(1ll<<k);
                    }else{
                         val+= set[k]*(1ll<<k);
                    }
               }

               ans=max(ans,val);
          }
      }
      cout<<ans<<endl;
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