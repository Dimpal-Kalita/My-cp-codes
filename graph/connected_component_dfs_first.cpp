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
  ll v;//no of vertices
  list<ll>* adj;
  Graph(ll v)
  {
    this->v = v;
    adj = new list<ll>[v];
  }
  void add_edge(ll n1, ll n2, bool bidir = true){
    adj[n1].push_back(n2);
    if(bidir){
      adj[n2].push_back(n1);
    }
  }
  /*void print(){
    for(auto row: this->adj){
      cout<<row.first<<"-->";
      for(T el: row.second){
        cout<<el<<", ";
      }
      cout<<endl;
    }
  }*/
    void dfsHelper(ll src, unordered_map<ll,bool> &visited){
      visited[src] = 1;
     // cout<<src<<" ";
      for(auto neighbour : this->adj[src]){
        if(!visited[neighbour]){
          dfsHelper(neighbour,visited);
        }
      }
    }
    void dfs(ll src){
      unordered_map<ll,bool> visited;
      dfsHelper(src,visited);
    }
    ll connectedcomp(){
      unordered_map<ll,bool> visited;
      ll result = 0;// stores the component
      fr(i,v-1){
        if(!visited[i]){
          //call dfs
          dfsHelper(i,visited);
          result++;
        }
      }
      return result;

    }
   
};
void solve(){
// dfs traverse all connected components

Graph g(6);
g.add_edge(0,1);
g.add_edge(2,1);
g.add_edge(3,2);
g.add_edge(4,5);
cout<<g.connectedcomp();
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