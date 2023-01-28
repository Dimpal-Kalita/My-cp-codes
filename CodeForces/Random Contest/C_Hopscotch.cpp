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



// hopscotch

void dk(){
     ll a, x, y;
     cin>>a>>x>>y;
     if(y%a==0){
            cout<<-1<<endl;
            return;
     }
     
     ll level= y/a;
     if(level%2==1 || level==0){
        if(-a / 2 - (a % 2) < x && x < a / 2 + (a % 2))
	    cout << (level ? level / 2 * 3 + 2 : 1) << '\n';
        else
            cout << "-1\n";
     }
     else {
        if(-a < x && x < 0)
	    cout << level / 2 * 3 << '\n';
        else if(0 < x && x < a)
            cout << level / 2 * 3 + 1 << '\n';
        else
            cout << "-1\n";
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