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
#define size(x)             int((x).size());
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
     string a, b;
     cin>>a>>b;

     int n=a.length(),m=b.length();
     if(a[n-1]==b[m-1]){
        cout<<"YES"<<endl;
        cout<<"*"<<a[n-1]<<endl;    
        return;
     }

     if(a[0]==b[0]){
        cout<<"YES"<<endl;
        cout<<a[0]<<"*"<<endl;
        return;
     }

     for(int i=0;i<n-1;i++){
        string t=a.substr(i,2);
        for(int j=0;j<m-1;j++){
            string s=b.substr(j,2);
            if(t==s){
                cout<<"YES"<<endl;
                cout<<"*"<<s<<"*"<<endl;
                return;
            }
        }
     }

     cout<<"NO"<<endl;
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