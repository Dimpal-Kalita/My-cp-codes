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





ll calc(string s){
     ll val=0;
     for(int i=0;i<s.size();i++){
          if(s[i]=='1'){
               val+=1<<i;
          }
     }
     return val;
}

typedef struct node{
     int days;
     string a,b;
}node;

void dk(){
     int n,m;
     cin>>n>>m;
     vector<node> v;
     vector<vl>adj(n+1);
     string s;
     cin>>s;
     for(int i=0;i<m;i++){
          node temp;
          cin>>temp.days>>temp.a>>temp.b;
          v.pb(temp);
          for(int j=0;j<n;j++){
               if(temp.a[j]=='1'){
                    adj[j].pb(i);
               }
          }
     }
     debug(adj);
     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

     pq.push({0,calc(s)});
     vector<int> vis(1<<(n+1),0);
     while(!pq.empty()){
          auto [days,val] =pq.top();
          pq.pop();

          if(vis[val]==1){
               continue;
          }
          vis[val]=1;
          if(val==0){
               cout<<days<<endl;
               return;
          }
          for(int i=0;i<n;i++){
               if(val&(1<<i)){
                    for(auto j:adj[i]){
                         ll temp=val;
                         for(int k=0;k<n;k++){
                              if(val&(1<<k) and v[j].a[k]=='1'){
                                   temp-=1<<k;
                              }
                              if(v[j].b[k]=='1'){
                                   temp|=1<<k;
                              }
                         }
                         pq.push({days+v[j].days,temp});
                    }
               }
          }

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