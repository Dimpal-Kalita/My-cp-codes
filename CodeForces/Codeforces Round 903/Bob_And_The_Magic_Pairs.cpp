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

    void insert(const string &s)
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
    }

    int checkPrefix(const string &s,const string &t)
    {
        int count=0;
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p=t[i]-'0';
            if(s[i]=='0' and t[i]=='1') {
               count+=tree[0].freq;
               p=1;
            }

            if(s[i]=='0' and t[i]=='0') {
               count+=tree[1].freq;
               p=0;
            }
            if (tree[p].next[s[i] - baseChar] == -1)
                return 0;
            p = tree[p].next[s[i] - baseChar];
        }
        return true;
    }

};

//    v->  1 ->  1 -> 0            -> 0
// a[i]->  1 ->  0 -> 1            -> 0
// a[j]->  0 ->  1 -> 1+case(0)    -> 0+case(1)
// a[i]^a[j]>v



void dk(){
     ll n,L,R;
     cin>>n>>L>>R;
     vl v(n);
     Trie t;
     for(auto &it:v){
          cin>>it;
          string s=bitset<32>(it).to_string();
          t.insert(s);
     }    
     ll ans=0;
     for(auto i:v){
           string s=bitset<32>(i).to_string();
           string s1=bitset<32>(L).to_string();
           string s2=bitset<32>(R).to_string();
           ans+=(t.checkPrefix(s,s2))-(t.checkPrefix(s,s1));
     } 
     cout<<ans/2<<endl;
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