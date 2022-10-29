#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
#define endl                "\n"
#define read(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define int                 long long
#define ld                  long double
#define printv(v)           for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl; 
void google(int t) {cout << "Case #" << t << ": ";}
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order, order_of_key

//************************************************NUMBER THEORY****************************************************
bool isPrime(int n)
{
if (n <= 1)return false;
if (n <= 3)return true;
if (n % 2 == 0 || n % 3 == 0)return false;
for (int i = 5; i * i <= n; i = i + 6) {
if (n % i == 0 || n % (i + 2) == 0)return false;
}
return true;
}
string get_binary( int n){
string str;
for( int i=31;i>=0;i--){
if((n>>i)&1){
str.push_back('1');
}else{
str.push_back('0');
}
}
 return str;
}
int bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}

//************************************************************************************************************************


void solve(){

    int n;
    cin>>n;
    vector<int>v(n);
    read(v);

    
    for(int i=n;i>=1;i--){
       set<int>st;
       map<int,int>mp;
       for(auto i:v){
        st.insert(i);
        mp[i]++;
       }
       int check=0;
       for(int j=i;j>=1;j--){
         auto it = st.lower_bound(j);
         if(it==st.end()){
            it--;
         }
         if(*it>j){
            if(it==st.begin()){
                check=1;
                break;
            }
            it--;
            if(*it>j){
                check=1;
                break;
            }
         }
         int num = *it;
         mp[num]--;
         if(mp[num]==0){
            st.erase(num);
         }

        if(st.empty()){
           break;
         }

         int num2 = *st.begin();
         mp[num2]--;
         if(mp[num2]==0){
            st.erase(num2);
         }
         st.insert(num2+j);
         mp[num2+j]++;

       }
       st.clear();
       mp.clear();
    
       for(auto i:v){
        st.insert(i);
        mp[i]++;
       }

      

       int check1=0;
       for(int j=i;j>=1;j--){
         auto it = st.lower_bound(j);
         if(it==st.end()){
            it--;
         }
         if(*it>j){
            if(it==st.begin()){
                check1=1;
                break;
            }
            it--;
            if(*it>j){
                check1=1;
                break;
            }
         }
         int num = *it;
         mp[num]--;
         if(mp[num]==0){
            st.erase(num);
         }
         
         if(st.empty()){
           break;
         }

         auto it2 = st.end();
         it2--; 
         int num2 = *it2;
         mp[num2]--;
         if(mp[num2]==0){
            st.erase(num2);
         }
         st.insert(num2+j);
         mp[num2+j]++;

       }

       if(check==0 and check1==0){
        cout<<i<<endl;
        return;
       }




    } 


    cout<<0<<endl;   







}







int32_t main(){
fast_io;
int q;
cin>>q;
while(q--){
    solve();
  
}



return 0;
}