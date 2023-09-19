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




const lld M_PI =3.14159265359;

typedef struct Data{
     lld x,y,z;
     lld r;
}data;



lld Volume(Data a,Data b) {

    lld d = sqrtl((b.x - a.x)*(b.x-a.x)+(b.y - a.y)*(b.y-a.y) + (b.z - a.z)*(b.z-a.z));


    if (d >= a.r + b.r) {
        return 0.0;
    }
    if(d <= abs(a.r - b.r)) {
        lld sR = (a.r < b.r) ? a.r : b.r;
        return ((lld)4 / (lld)3) * M_PI *sR*sR*sR;
    }
    
    lld ans= (1.0/12.0)*M_PI*(4.0*b.r+d)*(2.0*b.r-d)*(2.0*b.r-d);
    return ans;
     
//     lld h = a.r - (d*d - b.r*b.r + a.r*a.r) / (2.0 * d);

//     lld intersectionVolume = (1.0 / 3.0) * M_PI * h*h* (3* a.r - h);

//     return intersectionVolume;
}

void dk(){
      ll n;
      cin>>n;
      vector<Data>v;
      rep(i,0,n){
          Data it;
          cin>>it.x>>it.y>>it.z>>it.r;
          v.pb(it);
      }
      Data p;
      cin>>p.x>>p.y>>p.z>>p.r;
      lld ans=0;
      for(auto it:v){
          ans+= Volume(it,p);
      }
      cout<<setprecision(10)<<fixed<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<"Case #"<<i+1<<" :";
    dk();
   }
  return 0;
}