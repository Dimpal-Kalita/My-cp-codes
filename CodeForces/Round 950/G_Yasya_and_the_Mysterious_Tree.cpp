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



#ifndef ONLINE_JUDGE
#include ".vscode/debug.hpp";
#else
#define debug(...)
#define debugArr(arr, n)
#endif




class Trie{

public:
    const static int N = 2;
    const static char baseChar = 0;
    struct TrieNode
    {
        int next[N];
        bool isEnd;
        int freq;
        TrieNode()
        {
            for (int i = 0; i < N; i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
        }
    };

    vector<TrieNode> tree;
    Trie()
    {
        tree.push_back(TrieNode());
    }

    void insert(ll x)
    {
        int p = 0;
        tree[p].freq++;
        for(ll i=31;i>=0;i--){
            int b = (x>>i)&1LL;
            if(tree[p].next[b]==-1){
                tree[p].next[b] = tree.size();
                tree.push_back(TrieNode());
            }
            p = tree[p].next[b];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
    }

    ll max_xor(ll x){
          int p = 0;
          ll ans = 0;
          for(ll i=31;i>=0;i--){
               int b = (x>>i)&1LL;
               if(tree[p].next[!b]!=-1 and tree[tree[p].next[!b]].freq>0){
                         ans += (1<<i);
                         p = tree[p].next[!b];
               }else if(tree[p].next[b]!=-1 and tree[tree[p].next[b]].freq>0) {
                         p = tree[p].next[b];
               }else break;
          }
          return ans;
    }
    void erase(ll x)
    {
        int p = 0;
        tree[p].freq--;
        for(int i=31;i>=0;i--){
            int b = (x>>i)&1;
            p = tree[p].next[b];
            tree[p].freq--;
        }
    }
};


void dk(){
      ll n,m;
      cin>>n>>m;
      vector<vector<pll>>adj(n+1);
      rep(i,0,n-1){
          ll u,v,w;
          cin>>u>>v>>w;
          adj[u].pb({v,w});
          adj[v].pb({u,w});
      }
      // tries for even and odd depth nodes, sme parity nodes will create a  odd length cycle otherwise it will create odd length cycle
      vector<Trie>tries(2);
      vl depth(n+1);
      vl nodexor(n+1);
      function<void(ll,ll,ll,ll)>dfs = [&](ll u,ll p,ll d,ll x){
          depth[u] = d;
          nodexor[u] = x;
          tries[d%2].insert(x);
          for(auto v:adj[u]){
              if(v.F==p) continue;
              dfs(v.F,u,d+1,x^v.S);
          }

      };
      dfs(1,0,0,0);
      vector<array<ll,3>>query;
      vl ret;
      ll x=0;
      rep(i,0,m){
          char ch;
          cin>>ch;
          if(ch=='^'){
               ll v;
               cin>>v;
               x^=v;
          }else{
               ll node,weight;
               cin>>node>>weight;
               query.pb({node,weight,x});
               ll d = depth[node];
               ll nodex=nodexor[node];
               tries[d%2].erase(nodex);
               ll temp1 = tries[d%2].max_xor(weight^nodex);
               ll temp2 = tries[(d+1)%2].max_xor(weight^x^nodex);
               tries[d%2].insert(nodex);
               ll ans=max(temp1,temp2);
               ret.pb(ans);
          }
      }
      for(auto x:ret){
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