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


class TrieNode{
    bool flag=false;
    TrieNode* child[26];
    array<int, 26> cnt;
    public:
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
            cnt[i]=0;
        }
    }
    void insert(string s){
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=new TrieNode();
            }
            curr->cnt[index]++;
            curr=curr->child[index];
        }
        curr->flag=true;
    }
    bool search(string s){
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr=curr->child[index];
        }
        return curr->flag;
    }
    int count(string s){
        int ans=0;
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL){
                return 0;
            }
            curr=curr->child[index];
            ans=curr->cnt[index];
        }
        return ans; 
    }
    void remove(string s){
        TrieNode* curr=this;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL){
                return;
            }
            curr=curr->child[index];
        }
        curr->flag=false;
    }
};



void dk(){
    ll n,k;
    cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    TrieNode* root=new TrieNode();
    


}




int main()
{ 
    fast_io;
  
    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}