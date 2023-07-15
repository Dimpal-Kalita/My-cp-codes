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
      vector<ll>v(n);
      inp(v);
      string s;
      cin>>s;
      ll ans=0;
      vector<vl>m(n+1,vl(4,0)),x(n+1,vl(4,0));
      rep(i,0,n){
          rep(j,0,4) m[i+1][j]+=m[i][j];
          if(s[i]!='M') continue;
          if(v[i]<3) m[i+1][v[i]]++;
          else m[i+1][3]++;
      }
      for(int i=n-1;i>=0;i--){
          rep(j,0,4) x[i][j]+=x[i+1][j];
          if(s[i]!='X') continue;
          if(v[i]<3) x[i][v[i]]++;
          else x[i][3]++;
      }

      for(int i=0;i<n;i++){
          if(s[i]!='E') continue;
          if(v[i]==0){
                 ans+= (m[i][0]*x[i+1][0]);
                 ans+= (m[i][0]*x[i+1][2]);
                 ans+= (m[i][0]*x[i+1][3]);
                 ans+= (m[i][2]*x[i+1][0]);
                 ans+= (m[i][2]*x[i+1][2]);
                 ans+= (m[i][2]*x[i+1][3]);
                 ans+= (m[i][3]*x[i+1][0]);
                 ans+= (m[i][3]*x[i+1][2]);
                 ans+= (m[i][3]*x[i+1][3]);
                 ans+=2*(m[i][1]*x[i+1][0]);
                 ans+=2*(m[i][1]*x[i+1][1]);
                 ans+=2*(m[i][1]*x[i+1][3]);
                 ans+=2*(m[i][0]*x[i+1][1]);
                 ans+=2*(m[i][3]*x[i+1][1]);
                 ans+= 3*(m[i][1]*x[i+1][2]);
                 ans+= 3*(m[i][2]*x[i+1][1]);
          }
          else if(v[i]==1){
               ans+= 2*(m[i][0]*x[i+1][0]);
               ans+= 2*(m[i][0]*x[i+1][1]);
               ans+= 2*(m[i][0]*x[i+1][3]);
               ans+= 2*(m[i][1]*x[i+1][0]);
               ans+= 2*(m[i][3]*x[i+1][0]);
               ans+= 3*(m[i][2]*x[i+1][0]);
               ans+= 3*(m[i][0]*x[i+1][2]);
          }else if(v[i]==2){
               ans+= (m[i][0]*x[i+1][0]);
               ans+= (m[i][0]*x[i+1][2]);
               ans+= (m[i][0]*x[i+1][3]);
               ans+= (m[i][2]*x[i+1][0]);
               ans+= (m[i][3]*x[i+1][0]);
               ans+= 3*(m[i][1]*x[i+1][0]);
               ans+= 3*(m[i][0]*x[i+1][1]);
          }else {
               ans+= (m[i][0]*x[i+1][0]);
               ans+= (m[i][0]*x[i+1][2]);
               ans+= (m[i][0]*x[i+1][3]);
               ans+= (m[i][2]*x[i+1][0]);
               ans+= (m[i][3]*x[i+1][0]);
               ans+= 2*(m[i][1]*x[i+1][0]);
               ans+= 2*(m[i][0]*x[i+1][1]);
          }
      }
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