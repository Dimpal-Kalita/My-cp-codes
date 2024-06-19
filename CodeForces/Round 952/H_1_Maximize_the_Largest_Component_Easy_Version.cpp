#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
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


struct DSU {
     vector<int> s;
     DSU(int n): s(n, -1) {}
     int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
     bool join(int a, int b) {
          a = find(a), b = find(b);
          if (a == b) return false;
          if (s[a] > s[b]) swap(a, b);
          s[a] += s[b], s[b] = a;
          return true;
     }
     int size(int i) { return -s[find(i)]; }
     bool same(int a, int b) { return find(a) == find(b); }
};


vector<pll>dxy={{1,0},{-1,0},{0,1},{0,-1}};
void dk(){
     ll n,m;
     cin>>n>>m;
     vector<string>v(n);
     for(auto &i:v){
          cin>>i;
     }
     DSU dsu(n*m+1);
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if(v[i][j]=='.'){
                    continue;
               }
               for(auto [dx,dy]:dxy){
                    int x=i+dx,y=j+dy;
                    if(x<0||y<0||x>=n||y>=m||v[x][y]=='.'){
                         continue;
                    }
                    dsu.join(i*m+j,x*m+y);
               }
          }
     }
     ll ans=0;
     for(int i=0;i<n;i++){
          ll cur=0;
          set<ll>par;
          for(int j=0;j<m;j++){
               cur+=(v[i][j]=='.');
               if(v[i][j]=='#'){
                    par.insert(dsu.find(i*m+j));
               }
               if(i-1>=0 and v[i-1][j]=='#'){
                    par.insert(dsu.find((i-1)*m+j));
               }
               if(i+1<n and v[i+1][j]=='#'){
                    par.insert(dsu.find((i+1)*m+j));
               }
          }
          for(auto x:par){
               cur+=dsu.size(x);
          }
          ans=max(ans,cur);
     }
     for(int i=0;i<m;i++){
          ll cur=0;
          set<ll>par;
          for(int j=0;j<n;j++){
               cur+=(v[j][i]=='.');
               if(v[j][i]=='#'){
                    par.insert(dsu.find(j*m+i));
               }
               if(i-1>=0 and v[j][i-1]=='#'){
                    par.insert(dsu.find(j*m+i-1));
               }
               if(i+1<m and v[j][i+1]=='#'){
                    par.insert(dsu.find(j*m+i+1));
               }
          }
          for(auto x:par){
               cur+=dsu.size(x);
          }
          ans=max(ans,cur);
     }
     cout<<ans<<endl;
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