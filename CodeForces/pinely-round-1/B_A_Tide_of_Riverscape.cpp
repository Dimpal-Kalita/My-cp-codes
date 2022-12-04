// 2112048
// Dimpal Kalita
// CSE sec A

#include<bits/stdc++.h>


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


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




ll n, p;


void dk(){
     cin>>n>>p;
     string s;
     cin>>s; 
     ll count=0;

     for(ll i=0;i<n-p;i++){

        if(s[i]==s[i+p]){
            count++;
        }
        // cout<<s[i]<<" "<<s[i+p]<<" ";
        if(s[i]=='.' && s[i+p]=='.'){
            s[i]='0';
            s[i+p]='1';
        }
        if(s[i]!='.' && s[i+p]=='.'){
            if(s[i]=='1') s[i+p]='0';
            else s[i+p]='1';
        }
        if(s[i+p]!='.' && s[i]=='.'){
            if(s[i+p]=='0') s[i]='1';
            else s[i]='0';
        }
        // cout<<"changed to: "<< s[i]<<" "<<s[i+p]<<endl;

     } 

    for(ll i=0;i<n;i++){
        if(s[i]=='.') s[i]='1';
    }

    for(ll i=0;i<n-p;i++){
        if(s[i]!=s[i+p]){
            cout<<s<<endl;
            return;
        }
    }
    cout<<"No"<<endl;

}




int main()
{ 
    fast_io;
    
    //#ifndef ONLINE_JUDGE
    //file_io;
    //freopen("D:/cp/error.txt", "w+", stderr);
    //#endif

    int n=1;
    // cin>>n;
    for(int i=0;i<n;i++){
    //google(i+1);
    dk();
   }
  return 0;
}