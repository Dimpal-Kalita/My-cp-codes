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


class Trie{

public:
    const static int N = 2;
    const static char baseChar = '0';
    struct TrieNode
    {
        int next[N];
        bool isEnd;
        ll freq;
        ll val;
        TrieNode()
        {
            for (int i = 0; i < N; i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
            val=0;
        }
    };

    vector<TrieNode> tree;
    Trie()
    {
        tree.push_back(TrieNode());
    }

    void insert(vector<pair<char,ll>>&s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i].F - baseChar] == -1)
            {
                tree.push_back(TrieNode());
                tree[p].next[s[i].F - baseChar] = tree.size() - 1;
            }
            p = tree[p].next[s[i].F - baseChar];
            tree[p].val=s[i].S;
        }
        tree[p].isEnd = true;
    }

    // since in trie each prefix is stored only once the `val` is added only for unique prefixes
    ll countans(){
          ll sum=0;
          for(auto x:tree){
               sum=(sum+x.val)%md;
          }
          return sum;
    } 
};




Trie t;


// calculating answer for each prefix and inserting it on a trie
void func(string s){
     ll n=sz(s);
     stack<ll>st;
     ll ans=0,sum=0,ct=0;
     vector<pair<char,ll>> v;
     for(int i=0;i<n;i++){
          if(s[i]=='0'){
               if(st.empty()){

               }
               else if(st.top()==1){
                    st.pop();
                    if(!st.empty()) sum=(sum+1)%md;
                    st.push(1);
               }else{
                    sum=(sum+1)%md;
               }
               st.push(0);
          }else{
               if(!st.empty() and st.top()==1){

               }else{
                    st.push(1);
               }
          }
          v.pb({s[i],sum});
          ans=(ans+sum)%md;
     }
     t.insert(v);
}

void dk(){
      ll n;
      cin>>n;
      rep(i,0,n){
           string s;
           cin>>s;
           func(s); // process the string
      }
     cout<<t.countans()<<endl;
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