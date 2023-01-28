// 2112048
// Dimpal Kalita
// CSE sec A

#include<bits/stdc++.h>



using namespace std;




typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
typedef long double lld;


map<ll, ll>mp ={ {65,99} ,{66,121} ,{67,85}, {68, 75} ,{69,90} ,{70,88} ,{71,107} ,{72,98} ,{73,118} ,{74,122} ,{75,73} ,{76,100} ,{77,115} ,{78,104} ,{79,117} ,{80,114} ,{81,77} ,{82,105} ,{83,108} ,{84,78} ,{85,83} ,{86,86} ,{87,79} ,{88,116} ,{89,101} ,{90,110} ,{97,80} ,{98,103} ,{99,69} ,{100,102} ,{101,84} ,{102,89} ,{103,97} ,{104,87} ,{105,71} ,{106,72} ,{107,106} ,{108,68} ,{109,65} ,{110,109} ,{111,120} ,{112,81} ,{113,113} ,{114,70} ,{115,76} ,{116,82} ,{117,112} ,{118,67} ,{119,74} ,{120,66} ,{121,111} ,{122,119} };


void dk(){
      ll n;
      cin>>n;
      
      string s[n], t[n];
      for(ll i=0;i<n;i++){
          cin>>s[i];
      }
     
      
      for(ll i=0;i<n;i++){

            for(ll j=0;j<s[i].size();j++){
                  char ans=mp[s[i][j]];
                  cout<<ans;
            }
            cout<<" ";
      }

}




int main()
{ 

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n=1;
    for(int i=0;i<n;i++){
    dk();
   }
   
  return 0;
}