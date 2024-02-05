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

struct Tree {
     typedef ll T;
     static constexpr T unit = INT_MIN;
     T f(T a, T b) { return max(a, b); } // (any associative fn)
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
     T kth_from_left(ll k,ll R){
          ll l=0,r=R+1,ans=-1;
          while(l<r){
               ll mid=(l+r)/2;
               if(query(mid,R+1)>=k){
                    ans=mid;
                    l=mid+1;
               }
               else{
                    r=mid;
               }
          }
          if(query(ans,R+1)!=k) return -1;
          return ans;
     }
     ll kth_from_right(ll k,ll L){
          ll l=L,r=n,ans=-1;
          while(l<r){
               ll mid=(l+r)/2;
               if(query(L,mid+1)>=k){
                    ans=mid;
                    r=mid;
               }
               else{
                    l=mid+1;
               }
          }
          if(query(L,ans+1)!=k) return -1;
          return ans;
     }
};

struct Tree2 {
     typedef ll T;
     static constexpr T unit = INT_MAX;
     T f(T a, T b) { return min(a, b); } // (any associative fn)
     vector<T> s;
     int n;
     Tree2(int n = 0, T def = unit): s(2 * n, def), n(n) {}
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
      ll n;
      cin>>n;
      vl a(n),b(n);
      inp(a);
      inp(b);
      bool flag=1;
      for(int i=0;i<n;i++){
           if(a[i]>b[i]){
                flag=0;
                break;
           }
      }
      if(!flag){
          cout<<"NO"<<endl;
          return;
      }
      Tree A(n+1);
      Tree2 B(n+1);
      for(int i=0;i<n;i++){
           A.update(i,a[i]);
           B.update(i,b[i]);
      }



      for(int i=0;i<n;i++){
          if(a[i]==b[i]) continue;
          ll mx=0;
          
          ll l=A.kth_from_left(b[i],i);
          ll r=A.kth_from_right(b[i],i+1);
          // cout<<l<<" "<<r<<endl;
          if(l==-1 and r==-1){
               flag=0;
               break;
          }
          if(l==-1){
               ll R=B.query(i+1,r+1);
               if(b[i]>B.query(i+1,r+1)){
                    flag=0;
                    break;
               }
               mx=max(mx,B.query(i+1,r+1));
          }
          else if(r==-1){
               // cout<<b[i]<<" "<<B.query(l,i+1)<<endl;
               ll L=B.query(l,i+1);
               if(b[i]>L){
                    flag=0;
                    break;
               }
               mx=max(mx,L);
          }
          else{
               if(b[i]>B.query(l,i+1) and b[i]>B.query(i+1,r+1)){
                    flag=0;
                    break;
               }
               mx=max(mx,B.query(l,i+1));
               mx=max(mx,B.query(i+1,r+1));
          }
          if(mx!=b[i]){
               flag=0;
               break;
          }
      }
      cout<<(flag?"YES":"NO")<<endl;
}




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