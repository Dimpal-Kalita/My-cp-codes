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
typedef long double lld;
typedef pair<lld,lld> plld;
typedef pair<int,int>pii;
typedef unsigned long long ull;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



bool isRhombus(vector<plld>p){
    lld d1 = (p[0].F - p[1].F) * (p[0].F - p[1].F) + (p[0].S - p[1].S) * (p[0].S - p[1].S);
    lld d2 = (p[1].F - p[2].F) * (p[1].F - p[2].F) + (p[1].S - p[2].S) * (p[1].S - p[2].S);
    lld d3 = (p[2].F - p[3].F) * (p[2].F - p[3].F) + (p[2].S - p[3].S) * (p[2].S - p[3].S);
    lld d4 = (p[3].F - p[0].F) * (p[3].F - p[0].F) + (p[3].S - p[0].S) * (p[3].S - p[0].S);
    return (d1 == d2 && d2 == d3 && d3 == d4);
}

bool isRectangle(vector<plld>p){
    lld d1 = (p[0].F - p[1].F) * (p[0].F - p[1].F) + (p[0].S - p[1].S) * (p[0].S - p[1].S);
    lld d2 = (p[1].F - p[2].F) * (p[1].F - p[2].F) + (p[1].S - p[2].S) * (p[1].S - p[2].S);
    lld d3 = (p[2].F - p[3].F) * (p[2].F - p[3].F) + (p[2].S - p[3].S) * (p[2].S - p[3].S);
    lld d4 = (p[3].F - p[0].F) * (p[3].F - p[0].F) + (p[3].S - p[0].S) * (p[3].S - p[0].S);
    lld diag1=(p[0].F - p[2].F) * (p[0].F - p[2].F) + (p[0].S - p[2].S) * (p[0].S - p[2].S);
    lld diag2=(p[1].F - p[3].F) * (p[1].F - p[3].F) + (p[1].S - p[3].S) * (p[1].S - p[3].S);
    return (d1 == d3 && d2 == d4 && diag1==diag2);
}


lld polygonArea(vector<plld> v)
{
    lld area = 0.0;
    int j = 3;
    for (int i = 0; i < 4; i++)
    {
        area += (v[j].F + v[i].F) * (v[j].S - v[i].S);
        j = i;  
    }   
    return abs(area / 2.0);
}

void outp(vector<plld>p){
       
        cout<<fixed<<setprecision(2);
        cout<<"point: "<<p[3].F<<" "<<p[3].S<<endl;
        cout<<"area: "<<polygonArea(p)<<endl;
        cout<<"is rhombus: "<<(isRhombus(p)?"yes":"no")<<endl;
        cout<<"is rectangle: "<<(isRectangle(p)?"yes":"no")<<endl;
        cout<<"-------------------------"<<endl;
}

void dk(){
     vector<plld> p(3);
     for(int i=0;i<3;i++){
        cin>>p[i].F>>p[i].S;
     }
    
  
    vector<pair<pair<lld,lld>,vector<plld>>>mp;
    ll t=3;
    while(t>0){
        lld x=p[0].F-p[1].F+p[2].F,y=p[0].S-p[1].S+p[2].S;
        vector<plld>temp=p;
        temp.pb({x,y});
        mp.pb({{x,y},temp});
        t--;
        rotate(p.begin(),p.begin()+1,p.end());
    }

    sort(all(mp));
    for(auto x:mp){
        outp(x.S);
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