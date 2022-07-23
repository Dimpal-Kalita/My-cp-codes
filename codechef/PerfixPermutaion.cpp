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

ll k,n;
cin>>k>>n;
ll arr[n];
for (ll i = 0; i < n; i++)
{
    cin>>arr[i];
}
sort(arr, arr+n);

for (ll i = 0; i < n; i++)
{
    if(i<1)
    {
    for (ll j = arr[i]; j> 0;j-- )
  {
      cout<<j<<" ";
  }
    }
    else{
  for (ll j = arr[i]; j> arr[i-1];j-- )
  {
      cout<<j<<" ";
  }

    }
   
}
cout<<endl;

}
return 0;
}