/**
 * 
 * author: Dimpal Kalita
 * date: 15/05/2023 10:09:37
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


string decToHexa(int n)
{
    // ans string to store hexadecimal number
    string ans = "";
    
    while (n != 0) {
        // remainder variable to store remainder
        int rem = 0;
          
        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;
  
        // check if temp < 10
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
          
        // updating the ans string with the character variable
        ans += ch;
        n = n / 16;
    }
      
    // reversing the ans string to get the final result
    int i = 0, j = ans.size() - 1;
    while(i <= j)
    {
      swap(ans[i], ans[j]);
      i++;
      j--;
    }
    return ans;
}

string decToBinary(int n)
{
    string s="";
    int i = 0;
    while (n > 0) {
        s+= '0'+n % 2;
        n = n / 2;
        i++;
    }
  
   return s;
}


bool palindrom(string s){
     string t=s;
     reverse(all(t));
     return s==t;
}

void dk(){
      int n;
      cin>>n;
      string s= to_string(n);
      ll ct=0;
      if(palindrom(s)) ct++;
      if(palindrom(decToBinary(n))) ct++;
      if(palindrom(decToHexa(n))) ct++;
      cout<<(ct>=2?"ghavi":"fanni khordim")<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}