// 2112048
// Dimpal Kalita

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




void dk(){
    string s;
    cin>>s;
    if(s=="....."){
        cout<<"CAN'T TELL"<<endl;
        return;
    }
    string a="Alice", b="Bob", c="Cindy";
    if(s.length()==3){
        for(int i=0;i<3;i++){
            if(s[i]=='.' || s[i]==b[i]) continue;
            cout<<"SOMETHING'S WRONG"<<endl;
            return;
        }
        cout<<b<<endl;
        return;
    }
    else if(s.length()==5){
        bool flag1=1, flag2=1;
        for(int i=0;i<5;i++){
            if(s[i]=='.' || s[i]==a[i]) continue;
            flag1&=0;
        }
        
        if(flag1){
            cout<<a<<endl;
            return;
        }
        for(int i=0;i<5;i++){
            if(s[i]=='.' || s[i]==c[i]) continue;
            flag2&=0;
        }
        if(flag2){
            cout<<c<<endl;
            return;
        }
        cout<<"SOMETHING'S WRONG"<<endl;
        return;
    }
    else{
        cout<<"SOMETHING'S WRONG"<<endl;
        return;
    }

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