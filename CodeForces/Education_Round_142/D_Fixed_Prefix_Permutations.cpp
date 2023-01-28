// 2112048
// Dimpal Kalita

#include<bits/stdc++.h>


// #include <ext/pb_ds/detail/standard_policies.hpp>


using namespace std;
// using namespace __gnu_pbds;


#define md                  1000000007
#define pb                  push_back
#define fr(i,n)             for(ll i=0;i<n;i++)
#define fr1(i,k,n)          for(ll i=k;i<n;i++)
#define endl                "\n"
#define F                   first
#define S                   second
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key







struct Trie{
    const int K=11;
    struct Node{
        int cnt=0;
        Node* child[11];
        Node(){
            for(int i=0;i<11;i++){
                child[i]=NULL;
            }
        }
    };
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(vector<int> v){
        Node* cur=root;
        for(int i=0;i<v.size();i++){
            if(cur->child[v[i]]==NULL){
                cur->child[v[i]]=new Node();
            }
            cur=cur->child[v[i]];
            cur->cnt++;
        }
    }
    int query(vector<int> v){
        Node* cur=root;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(cur->child[v[i]]==NULL){
                return ans;
            }
            cur=cur->child[v[i]];
            ans++;
        }
        return ans;
    }
};




void dk(){
    int n,m;
    cin>>n>>m;
    Trie tr;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        inp(v[i]);
        vector<int> ind(m, 0);
        for(int j=0;j<m;j++){
            ind[v[i][j]-1]=j+1;
        }
        tr.insert(ind);
    }

    for(int i=0;i<n;i++){
        cout<<tr.query(v[i])<<" ";
    }
    cout<<endl;
}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}