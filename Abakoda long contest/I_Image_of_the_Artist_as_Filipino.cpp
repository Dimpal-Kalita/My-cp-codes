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



ll N;



map<vector<string>,vector<string>>anti, clck, miH, miV;
void rotate90Anticlockwise(vector<string>&arr){
   ll n=N;
   if(anti.count(arr)) {
        arr=anti[arr];
        return;
   }
   vector<string>temp=arr;
   for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            // Swapping elements after each iteration in Anticlockwise direction
            char temp=arr[i][j];
            arr[i][j]=arr[j][n-i-1];
            arr[j][n-i-1]=arr[n-i-1][n-j-1];
            arr[n-i-1][n-j-1]=arr[n-j-1][i];
            arr[n-j-1][i]=temp;
        }
    }
    anti[temp]=arr;

}
void rotate90Clockwise(vector<string>&a)
{
    
    if(clck.count(a)) {
        a=clck[a];
        return;
    }
    vector<string>temp=a;
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) { 
            char temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
    clck[temp]=a;
}
 
void mirrorH(vector<string>&s){
    if(miH.count(s)) {
        s=miH[s];
        return;
    }
    vector<string>temp=s;
    for(int i=0;i<N;i++){
        reverse(all(s[i]));
    }
    miH[temp]=s;
}


void mirrorV(vector<string>&s){
    if(miV.count(s)) {
        s=miV[s];
        return;
    }
    vector<string>temp=s;
    reverse(all(s));
    miV[temp]=s;
}




void dk(){
      cin>>N;
      vector<string>s(N);

      for(int i=0;i<N;i++) cin>>s[i];

      
      string op;
      cin>>op;
      reverse(all(op));
      for(auto &it:op){
        if(it=='L') it='R';
        else if(it=='R') it='L';
      }

      ll Rct=(count(all(op),'R'))%6;
      ll Lct=(count(all(op),'L'))%6;
      ll Hct=(count(all(op),'H'))%2;
      ll Vct=(count(all(op),'V'))%2;

      map<pair<vector<string>,char>,vector<string>>mp;

      for(auto it:op){
        if(it=='R'){
            if(Rct==0) continue;
            Rct--;
            rotate90Clockwise(s);
        }
        else if(it=='L'){
            if(Lct==0) continue;
            Lct--;
            rotate90Anticlockwise(s);
        }
        else if(it=='H'){
            if(Hct==0) continue;
            Hct--;
            mirrorH(s);
        }
        else if(it=='V'){
            if(Vct==0) continue;
            Vct--;
            mirrorV(s);
        }

      }

      for(int i=0;i<N;i++){
        cout<<s[i]<<endl;
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