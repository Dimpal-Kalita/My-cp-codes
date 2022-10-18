#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// A Random number between l, r
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

signed main()
{

  
     //test case

     int t= rand(1,1000);
     cout<<t<<endl;
     int temp=t;

     while(t--){
        int n= rand(1,200000/temp);
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            int k= rand(0,1);  
            cout<<k; 
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            int k= rand(1,100);  
            cout<<k<<" "; 
        }
        cout<<endl;

     }
  

}