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




void dk(){
      ll n, m;
      cin>>n>>m;
      string s, t;
      cin>>s>>t;
      
      vector<int> ct1(26, 0);
      if(n<m) swap(s,t), swap(n,m);

      for(int i=0;i<n;i++){
        ct1[s[i]-'a']++;
      }
      // debug(ct1)

      for(int i=0;i<m;i++){
      
        if(ct1[t[i]-'a']>0) ct1[t[i]-'a']--;
        else{
          cout<<"NO"<<endl;
          return;
        }

      }
      // debug(ct1)
      ll ct=0;
      for(int i=0;i<26;i++){
        if(ct1[i]%2){
          ct++;
         }
         if(ct>1){
          cout<<"NO"<<endl;
          return;
         }
      }  
      cout<<"YES"<<endl;
      return;

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