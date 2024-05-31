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
    const static int N = 26;
    const static char baseChar = 'a';
    struct TrieNode
    {
        int next[N];
        bool isEnd;
        int freq;
        int ind;
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

    void insert(const string &s,int index)
    {
        int p = 0;
        tree[p].freq++;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
            {
                tree.push_back(TrieNode());
                tree[p].next[s[i] - baseChar] = tree.size() - 1;
            }

            p = tree[p].next[s[i] - baseChar];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
        tree[p].ind=index;
    }
    int checkString(const string &s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tree[p].next[s[i] - baseChar] == -1)
                return false;

            p = tree[p].next[s[i] - baseChar];
        }

        return index;
    }

};



void dk(){
     ll n,m;
     cin>>n>>m;
     Trie t;
     rep(i,0,n){
          string s;
          cin>>s;
          t.insert(s,i+1);
     }
     string recent="";
     vl ans(n);
     ll tot=0;
     rep(i,0,m){
          string s;
          getline(cin,s);
          ll ans=0;
          s.pop_back();
          ll ind=0;
          while(ind<sz(s)){
               string temp="";
               while(ind<sz(s) and s[ind]!=' '){
                    temp+=s[ind];
                    ind++;
               }
               tot++;
               if(t.checkString(temp) or recent==temp){
               }else{
                    
               }
               ind++;
          }
          cout<<ans<<endl;
     }
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