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
#define sz(x)             int((x).size());
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



struct Node{
    int maxPrefixSum;
    int maxSuffixSum;
    int totalSum;
    int maxSubarraySum;
  
    Node()
    {
        maxPrefixSum = maxSuffixSum = maxSubarraySum = -1e8;
        totalSum = -1e8;
    }
};

template <class T> struct SegTree {
    const T ID = node(0);
    int n; vector <T> seg;
    T comb(T a, T b) {
        node Parentnode;
         parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
                                  leftChild.totalSum +
                                  rightChild.maxPrefixSum);
  
        parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
                                    rightChild.totalSum +
                                    leftChild.maxSuffixSum);
    
        parentNode.totalSum = leftChild.totalSum +
                            rightChild.totalSum;
    
        parentNode.maxSubarraySum = max({leftChild.maxSubarraySum,
                                        rightChild.maxSubarraySum,
                                        leftChild.maxSuffixSum +
                                        rightChild.maxPrefixSum});
    
        return parentNode;
    }
    SegTree(int _n) { n = _n; seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void update(int idx, T val) {
        seg[idx += n] = val;
        for (idx /= 2; idx; idx /= 2) pull(idx);
    }
    T query(int l, int r) {
        T lnode = ID, rnode = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) lnode = comb(lnode, seg[l ++]);
            if (r & 1) rnode = comb(seg[-- r], rnode);
        }
        return comb(lnode, rnode);
    }
};

void dk(){
     ll n, k, x;
     cin>>n>>k>>x;
     vector<ll> v(n);
     
     for(auto &it:v){
        cin>>it;
        it-=x;
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