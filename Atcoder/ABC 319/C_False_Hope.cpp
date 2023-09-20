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



vector<vector<ll>>rows(vector<vl>&v){
     int n=v.size();
     int m=v[0].size();
     vector<vector<ll>>ans;
     for(int i=0;i<n;i++){
          map<ll,ll>mp;
          vl temp;
          for(int j=0;j<m;j++){
               mp[v[i][j]]++;
          }
          if(mp.size()==2){
               for(int j=0;j<m;j++){
                    if(mp[v[i][j]]==1){
                         temp.pb(i*m+j);   
                    }
               }
               for(int j=0;j<m;j++){
                    if(mp[v[i][j]]==2){
                         temp.pb(i*m+j);
                    }
               }
               ans.pb(temp);
          }
     }
     return ans;
}
vector<vl>cols(vector<vl>&v){
     int n=v.size();
     int m=v[0].size();
     vector<vector<ll>>ans;
     for(int i=0;i<m;i++){
          map<ll,ll>mp;
          vl temp;
          for(int j=0;j<n;j++){
               mp[v[j][i]]++;
          }
          if(mp.size()==2){
               for(int j=0;j<n;j++){
                    if(mp[v[j][i]]==1){
                         temp.pb(j*m+i);   
                    }
               }
               for(int j=0;j<n;j++){
                    if(mp[v[j][i]]==2){
                         temp.pb(j*m+i);
                    }
               }
               ans.pb(temp);
          }
     }
     return ans;
}

vector<vl>diag(vector<vl>&v){
     int n=3,m=3;
     vector<vector<ll>>ans;
     map<ll,ll>mp;
     vl temp;
     for(int i=0;i<n;i++){
          mp[v[i][i]]++;
     }
     if(mp.size()==2){
          for(int i=0;i<n;i++){
               if(mp[v[i][i]]==1){
                    temp.pb(i*m+i);   
               }
          }
          for(int i=0;i<n;i++){
               if(mp[v[i][i]]==2){
                    temp.pb(i*m+i);
               }
          }
          ans.pb(temp);
     }
     mp.clear();
     temp.clear();
     for(int i=0;i<n;i++){
          mp[v[i][n-i-1]]++;
     }
     if(mp.size()==2){
          for(int i=0;i<n;i++){
               if(mp[v[i][n-i-1]]==1){
                    temp.pb(i*m+n-i-1);   
               }
          }
          for(int i=0;i<n;i++){
               if(mp[v[i][n-i-1]]==2){
                    temp.pb(i*m+n-i-1);
               }
          }
          ans.pb(temp);
     }
     return ans;
}

void dk(){
     ll n=3,m=3;
     vector<vl>v(3,vl(3,0));
     rep(i,0,3){
          inp(v[i]);
     }
     ll ans=0;
     vector<ll>index(9,0);
     iota(all(index),0);
     vector<vl>find=rows(v);
     vector<vl>temp=cols(v);
     for(auto i:temp){
          find.pb(i);
     }
     temp=diag(v);
     for(auto i:temp){
          find.pb(i);
     }

     ll ct=0;
     do{
          vl vis(9,0);
          for(auto i:index){
               bool flag=0;
               for(auto it:find){
                    if(it[0]==i and vis[it[1]] and vis[it[2]]){
                         flag=1;
                         ct++;
                         break;
                    }
               }
               if(flag) break;
               vis[i]=1;
          }
     }while(next_permutation(all(index)));
     lld div=1;
     for(int i=2;i<=9;i++) div*=i;
     cout<<fixed<<setprecision(10)<<1-ct/div<<endl;
}



int main()
{ 
    fast_io;
  
    int _=1;
//     cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}