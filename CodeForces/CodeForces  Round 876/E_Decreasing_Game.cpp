/**
 * 
 * author: Dimpal Kalita
* 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
// #define endl                " \n"
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








vector<vl>dp(301,vl(1e5,-1));
ll n;
vl v;
ll recur(ll ind,ll sum,ll tot){
     if(tot==2*sum){
          return dp[ind][sum]=1;
     }
     if(2*sum>tot || ind==n){
          return dp[ind][sum]=0;
     }
     if(dp[ind][sum]!=-1){
          return dp[ind][sum];
     }
     return dp[ind][sum]=(recur(ind+1,sum+v[ind],tot)||recur(ind+1,sum,tot));
}

vl a,b;

void dk(){
     cin>>n;
     v.resize(n);
     inp(v);
     ll sum=accumulate(all(v),0LL);
     bool val=recur(0,0,sum);

     if(!val){
          cout<<"First"<<endl;
          while(1){
               ll ind=0;
               for(int i=0;i<n;i++){
                    if(v[i]>0){
                         ind=i;
                         break;
                    }
               }
               cout<<ind+1<<endl;
               ll x;
               cin>>x;
               if(x==0){
                    return;
               }
               x--;
               ll d=min(v[x],v[ind]);
               v[x]-=d;
               v[ind]-=d;
          }
     }


     int i=n-1, j=sum/2;
     while(i>=0 and j>0){
          if(j-v[i]>=0 and dp[i][j-v[i]]==1){
               a.pb(i);
               j-=v[i];
          }
          i--;
     }

     sort(all(a));
     for(int i=0;i<n;i++){
          if(binary_search(all(a),i)) continue;
          b.pb(i);
     }


     cout<<"Second"<<endl;
     while(1){
          ll x;
          cin>>x;
          if(x==0){
               return;
          }
          x--;
          ll ind=0;
          if(binary_search(all(a),x)){
               for(auto i:b){
                    if(v[i]>0){
                         ind=i;
                         break;
                    }
               }
          }else{
               for(auto i:a){
                    if(v[i]>0){
                         ind=i;
                         break;
                    }
               }
          }
          cout<<ind+1<<endl;
          ll d=min(v[x],v[ind]);
          v[x]-=d;
          v[ind]-=d;
     }

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