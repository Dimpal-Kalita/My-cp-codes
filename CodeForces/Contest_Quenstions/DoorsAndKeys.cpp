#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
int count=0;
for (int i = 0; i <6; i++)
{
   if(s[i]=='R' || s[i]=='G' || s[i]=='B')
   {
       for (int j = 0; j < i; j++)
       {
           if(s[j]==s[i]+32)
           {
               count++;
           }
       }
    }
}
if(count==3)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;

}
return 0;
}