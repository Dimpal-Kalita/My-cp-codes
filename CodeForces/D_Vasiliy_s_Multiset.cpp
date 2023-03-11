// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key






/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(ll t) {cerr << t;}
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





class TrieNode{
    TrieNode* child[2];
    array<int, 2> cnt;
    public:
    TrieNode(){
        for(int i=0;i<2;i++){
            child[i]=NULL;
            cnt[i]=0;
        }
    }
    void insert(string s){
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'0';
            if(curr->child[index]==NULL){
                curr->child[index]=new TrieNode();
            }
            curr->cnt[index]++;
            curr=curr->child[index];
        }
    }
 
    ll query(string s){
        string ans="";
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'0';
            if(!curr->cnt[index] || curr->child[index]==NULL){
                index= 1-index;
            }
            if(!curr->cnt[index] && curr->child[index]==NULL){
                return 0;
            }
            curr=curr->child[index];
            ans+=to_string(index);
        }
        // debug(ans);
        return stol(ans, 0, 2);
    }
    void remove(string s){
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'0';
            if(curr->child[index]==NULL){
                return;
            }
            curr->cnt[index]--;
            curr=curr->child[index];
        }
   }
};



TrieNode *root=new TrieNode();

void dk(){
    string s=bitset<30>(0).to_string();
    root->insert(s);
    char ch;
    cin>>ch;
    if(ch=='+'){
        int n;
        cin>>n;
        string s=bitset<30>(n).to_string();
        root->insert(s);
    }
    if(ch=='-'){
        int n;
        cin>>n;
        string s=bitset<30>(n).to_string();
        root->remove(s);
    }
    if(ch=='?'){
        ll n;
        cin>>n;
        string s=bitset<30>(n).to_string();
        for(auto &it:s){
            if(it=='1') it='0';
            else it='1';
        }
        // debug(s);
        ll x=root->query(s);
        cout<<(n^x)<<endl;
    }

}




int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}