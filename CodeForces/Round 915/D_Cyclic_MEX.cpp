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
     vl vp;
     ll ind=0;
     for(int i=0;i<n;i++){
          if(v[i]==0){
               ind=i;
               break;     
          }
     } 
     for(int i=ind+1;vp.size()<n;i++){
          vp.pb(v[i%n]);
     }
     debug(vp);
     stack<pll>st;
     ll cur=n,ans=n;
     st.push({0,1});     
     for(int i=0;i<n-1;i++){
          ll len=1;
          while(st.top().F>vp[i]){
               cur-=st.top().S*st.top().F;
               len+=st.top().S;
               st.pop();
          }
          cur+=len*vp[i];
          st.push({vp[i],len});
          ans=max(ans,cur);
     }
     cout<<ans<<endl;
}

// make the array ending at 0, not sum of mex will be n only
// one by one transfer the elements from front to the back of the array and calculate new answer
// one thing to notice that smaller appending the smaller elements at the back affects the answer more
// keep a track how many mex from the back are affected by transfering the element from front to back
// let us consider an element x affects l number of mex from the back
// now another element y less than x will affect more than l mex from the back so removing x from the stack and add to the affected length 
// 5 4 3 2 1 0 - 0 0 0 0 0 6
// 4 3 2 1 0 5 - 0 0 0 0 5 6  = affected length 1
// 3 2 1 0 5 4 - 0 0 0 4 4 6  = affected length 2
// 2 1 0 5 4 3 - 0 0 3 3 3 6  = affected length 3 

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