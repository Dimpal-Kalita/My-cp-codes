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
        string s, t;
        cin>>s>>t;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='B' && t[i]=='W' && s[i+1]=='W' && t[i+1]=='B'){
                cout<<"NO"<<endl;
                return;
            }
            if(t[i]=='B' && s[i]=='W' && t[i+1]=='W' && s[i+1]=='B'){
                cout<<"NO"<<endl;
                return;
            }
        }
    
    
        bool flag=1;
        
        if(s[0]=='B' && t[0]=='B') flag=0;

        for(int i=0;i<n;i++){

            if(flag && s[i]=='B' && t[i]=='B') cnt++;
            else if(cnt>0){
                if(cnt%2==0){
                    if(s[i-cnt-1]!=s[i] && t[i-cnt-1]!=t[i]){
                        cout<<"NO"<<endl;
                        return;
                    }
                } else {
                    if(s[i-cnt-1]!=t[i] && t[i-cnt-1]!=s[i]){
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                cnt=0;
            }
    
            if(s[i]!=t[i]) flag=1;
        }

        cout<<"YES"<<endl;
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