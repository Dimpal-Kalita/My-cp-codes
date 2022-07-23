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
ll n,count=0;
cin>>n;
ll arr[n];
for (int i = 0; i < n ; i++)
{
    cin>>arr[i];
}
for (int i = 0; i < n; i++)
{
    if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
    {  if(i+2<n)
        {
            if(arr[i+1] < arr[i+2])
            {
                arr[i+1] = max(arr[i+2] ,arr[i]);
               
                count++;
            }
            else
            {
                arr[i] = max(arr[i-1] , arr[i+1]);
               
                count++;
            }
        }
        else
        arr[i]=arr[i+1];
         count++;
        
    }
}
cout<<count<<endl;
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}

cout<<endl;
}

return 0;
}