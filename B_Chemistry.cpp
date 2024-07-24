#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<char, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         string s;
//         cin>>s;
//         msi m;
//         REP(i,0,n-1){
//             m[s[i]]++;
//         }
//         int count=0,single=0;
//         for(auto it:m){
//             if(it.second%2!=0){
//                 single++;
//                 it.second--;

//             }
//             count=(it.second)/2+count;
//         }
//         int temp=k-single;
//         if(temp<=0){
//             cout<<"YES"<<endl;
//         }
//         else{
//             if(temp%2==0){

//             }
//             else{
//                 cout<<"NO"<<endl;
//             }
//         }

//     }
// }
int main(){
    int t;
    cin>>t;
    while(t--){
int n,k;cin>>n>>k;

     string s;cin>>s;
     map<char,int>mp;
     for(auto it:s) mp[it]++;
     int cnt=0;
     for(auto it:mp) {
        if(it.second  &1) ++cnt;
     }
    //  cout<<cnt<<endl;
     if(cnt <=k|| cnt-1<=k) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;}
}