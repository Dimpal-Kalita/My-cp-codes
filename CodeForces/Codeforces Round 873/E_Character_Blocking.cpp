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
     ll n,t,q;
     // cin>>n;
     vector<string>s(2);
     cin>>s[0]>>s[1];
     pair<ll,ll> cnt={0,0};
     n=s[0].length();
     rep(i,0,n){
          if(s[0][i]==s[1][i]) cnt.F++;
     }

     map<ll,ll> mp;
     cin>>t>>q;
     for(int i=0;i<q;i++){
          if(mp[i]>0){
               ll ind=mp[i]-1;
               cnt.S--;
               if(s[0][ind]==s[1][ind]) cnt.F++;
          }
          ll type;
          cin>>type;
          if(type==1){
               ll ind;
               cin>>ind;
               mp[i+t]=ind;
               ind--;
               cnt.S++;
               if(s[0][ind]==s[1][ind]) cnt.F--;
          }
          else if(type==2){
               ll x1,x2,ind1,ind2;
               cin>>x1>>ind1>>x2>>ind2;
               x1--,ind1--,x2--,ind2--;

               if(s[0][ind1]==s[1][ind1]) cnt.F--;
               if(s[0][ind2]==s[1][ind2]) cnt.F--;

               swap(s[x1][ind1],s[x2][ind2]);
               
               if(s[0][ind1]==s[1][ind1]) cnt.F++;
               if(s[0][ind2]==s[1][ind2]) cnt.F++;

          }else{
               cout<<((n-cnt.S)==cnt.F?"YES":"NO")<<endl;
          }
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