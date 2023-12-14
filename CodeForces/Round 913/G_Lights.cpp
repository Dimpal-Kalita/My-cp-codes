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
     string s;
     cin>>s;
     s="0"+s;
     vector<vl>adj(n+1);
     vector<ll>in(n+1,0);
     rep(i,1,n+1){
          ll x;
          cin>>x;
          adj[i].pb(x);
          in[x]++;
     }
     vector<vl>cycle;
     vector<ll>vis(n+1,0),par(n+1,0);
     vector<ll>ans;
     map<ll,ll>mp;
     function<void(ll,ll)> dfs=[&](ll u,ll p){
          vis[u]=1;
          par[u]=p;
          for(auto x: adj[u]){
               if(!vis[x]){
                    dfs(x,u);
               }
               else if(vis[x]==1){
                    ll cur=u;
                    vector<ll>v;
                    while(cur!=x){
                         v.pb(cur);
                         cur=par[cur];
                    }
                    v.pb(x);
                    cycle.pb(v);
               }
          }
          vis[u]=2;
     };
     
     for(ll i=1;i<=n;i++){
          if(!vis[i]){
               dfs(i,-1);
          }
     }

     queue<ll>q;
     for(ll i=1;i<=n;i++){
          if(in[i]==0){
               q.push(i);
          }
     }
     
     for(auto v:cycle){
          for(auto x: v){
               mp[x]=1;
          }
     }
     
     while(!q.empty()){
          ll u=q.front();
          q.pop();
          if(mp[u]) continue;
          if(s[u]=='1') ans.pb(u);
          for(auto x: adj[u]){
               if(!ans.empty() and ans.back()==u){
                    if(s[x]=='1') s[x]='0';
                    else s[x]='1';
               }
               in[x]--;
               if(in[x]==0){
                    q.push(x);
               }
          }
     }
     for(auto v: cycle){
          reverse(all(v));
          ll firstone=-1,secondone=-1,ct=0;
          for(int i=0;i<sz(v);i++){
               if(s[v[i]]=='1'){
                    if(firstone==-1){
                         firstone=i;
                    }
                    else{
                         secondone=i;
                    }
                    ct++;
               }
          }
          if(ct%2){
               cout<<-1<<endl;
               return;
          }
          if(ct==0) continue;
          vl ttt=v;
          rotate(v.begin(),v.begin()+firstone,v.end());
          vector<ll>temp,temp2;
          ll CT=ct;
          for(int i=0;i<sz(v);i++){
               if(s[v[i]]=='1'){
                    ct--;
               }
               if(ct%2) temp.pb(v[i]);
               else continue;
          }
          ct=CT;
          v=ttt;
          rotate(v.begin(),v.begin()+secondone,v.end());
          for(int i=0;i<sz(v);i++){
               if(s[v[i]]=='1'){
                    ct--;
               }
               if(ct%2) temp2.pb(v[i]);
               else continue;
          }
          if(temp.size()<temp2.size()){
               ans.insert(ans.end(),all(temp));
          }
          else{
               ans.insert(ans.end(),all(temp2));
          }
     }
     cout<<sz(ans)<<endl;
     for(auto x: ans){
          cout<<x<<" ";
     }
     cout<<endl;

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