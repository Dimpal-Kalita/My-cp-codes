#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
int main()
{
ll count1=0, count2=0;
string s1;
string s2;
cin>>s1;
cin>>s2;
ll i=0;
for (i = 0; i<s1.size(); i++) {
      if(s1[i] >= 'a' && s1[i] <= 'z') {
         s1[i] = s1[i] - 32;
         
      }
   }
   for (i = 0; i<s2.size(); i++) {
      if(s2[i] >= 'a' && s2[i] <= 'z') {
         s2[i] = s2[i] - 32;
         
      }
   }
  
if(s1==s2)
cout<<"0"<<endl;
else if(s1>s2)
cout<<"1"<<endl;
else
cout<<"-1"<<endl;

    return 0;
}