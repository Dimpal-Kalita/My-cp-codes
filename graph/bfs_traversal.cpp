#include<bits/stdc++.h>
using namespace std;


#define ll                  long long
#define md                  1000000007
#define pb                  push_back
#define mp                  make_pair
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define re(v,n)             v.resize(n)
#define inp(v)              for(auto &x: v) cin>>x           
#define dsort(a)            sort(a,a+n,greater<int>())
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
class Graph{
public:
   list< ll > adj;
  ll v;
  graph(ll v){
    this->v = v;
    adj.resize(v);
  } 
  void add_edge(ll n1, ll n2, bool bidir = true){
    adj[n1].push_back(n2);
    if(bidir){
      adj[n2].push_back(n1);
    }
  }
  void print(){
    for(auto row: this->adj){
      cout<<row.first<<"-->";
      for(T el: row.second){
        cout<<el<<", ";
      }
      cout<<endl;
    }
  }
  void bfs( ll s){
      vector<bool> visited(v, false);
      list<ll> queue;
      visited[s]= true;
      queue.pb(s);
      while(!queue.empty()){
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(auto adjecent: adj[s]){
          if(!visited[adjecent]){
            visited[adjecent]= true;
            queue.pb(adjecent);
          }
        }
      }

  } 
};
void solve(){
// using unordered-map is better in graph then vector
// entry in ordered map = O(logn) unordered- map = O(1)
// because of missing vertex .. vector occupies more space
graph g1(4);
//pass 3rd value false to get unidirectoinal graph

g1.add_edge(0,1);
g1.add_edge(0,2);
g1.add_edge(1,2);
g1.add_edge(2,0);
g1.add_edge(2,3);
g1.add_edge(3,3);
g1.bfs(2);
return;
}
int main()
{ 
fast_io;
#ifndef ONLINE_JUDGE
file_io;
#endif
ll n=1;
for(ll i=0;i<n;i++){
  cerr<<"Case #"<<i+1<<": ";
  solve();
}
return 0;
}