/**
 * 
 * author: Dimpal Kalita
 * date: 11/11/2023 09:28:25
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

const ll inf = 1e15;

struct Tree {
     typedef struct node{
          ll val;
          ll ind;
     } T;
     static constexpr T unit = {-inf,-1};
     T f(T a, T b) {
          if(a.val>b.val){
               return a;
          }else{
               return b;
          }
     } 
     vector<T> s;
     int n;
     Tree(int n = 0, T def = unit): s(2 * n, def), n(n) {}
     void update(int pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
               s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
     }
     T query(int b, int e) { // query [b, e)
          T ra = unit, rb = unit;
          for (b += n, e += n; b < e; b /= 2, e /= 2) {
               if (b % 2) ra = f(ra, s[b++]);
               if (e % 2) rb = f(s[--e], rb);
          }
          return f(ra, rb);
     }
};

void dk(){
      ll n,m;
      cin>>n>>m;
      vl v(n);
      inp(v);
      map<ll,ll>mp;
      ll sum=accumulate(all(v),0LL),q=0;
      rep(i,0,m){
          ll x,y;
          cin>>x>>y;
          mp[x]+=y;
          q+=y;
      }
      Tree t(n+1);
      for(int i=0;i<n;i++){
          t.update(i,{v[i],i});
      }
      vector<ll>dp(n+1);
      for(int i=0;i<n;i++){
          dp[i]=(v[i]-mp[i+1]);
      }

      vl ans;
      ll last=0;
      sum-=q;
      ans.pb(sum);
      map<ll,ll>vis;
      for(int i=1;i<n;i++){
          ll x=dp[last];
          ll xx=last+1;
          
          while(vis[xx]){
               x-=mp[xx];
               xx++;
          }

          auto y=t.query(xx,n+1);

          if(y.ind!=-1 and y.val>x){
               sum-=y.val;
               ans.pb(sum);
               t.update(y.ind,{-inf,-1});
               vis[y.ind]=1;
          }else{
               sum-=x;
               ans.pb(sum);
               vis[last]=1;
               while(vis[last]) last++;
          }
      }

      reverse(all(ans));
      for(auto i:ans){
          cout<<i<<" ";
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