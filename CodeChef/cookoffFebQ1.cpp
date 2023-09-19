#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

int main()
{
ll t;
cin>>t;
while(t--)
{
int n,m,count=0,sum=0;
cin>>n>>m;
int arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
sort(arr,arr+n);
for (int i = 0; i < count; i++)
{
  sum=sum+arr[i];
  count++;
  if(sum>=m)
  {
      break;
  }

}
cout<<n-count<<endl;

}
return 0;
}