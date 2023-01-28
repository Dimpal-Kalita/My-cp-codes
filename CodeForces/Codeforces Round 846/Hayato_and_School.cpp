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
     ll n;
     cin>>n;
     vector<ll> v(n);
     inp(v);
     ll o=0, e=0;
     for(auto it:v){
        if(it%2) o++;
        else e++;
     }

     if(o>=3){
        o=3;
        cout<<"YES"<<endl;
        ll ct=0;
        for(int i=0;i<n;i++){
            if(o>0 && v[i]%2){
                cout<<i+1<<" ";
                o--;
            }
        }
        cout<<endl;
        return;
     }
     if(e>=2 && o>=1){
        e=2, o=1;
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){

            if(e>0 && v[i]%2==0){
                cout<<i+1<<" ";
                e--;
            }
            if(o>0 && v[i]%2==1){
                cout<<i+1<<" ";
                o--;
            }
        }
        cout<<endl;
        return;
     }
     cout<<"NO"<<endl;
      


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