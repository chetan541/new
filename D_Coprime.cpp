#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
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

int main(){
    int t;cin>>t;
    while(t--){
         int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   unordered_map<int,int> mp;
    for(int i=n-1;i>=0;i--){
        if(mp[arr[i]]==0){mp[arr[i]]=i;}
    }
    int maxi = -1;
   for(auto it : mp){
        int t = it.first;
        for(auto xt : mp){
            if(__gcd(it.first,xt.first)==1){
                maxi = max((it.second+xt.second+2),maxi);
            }
        }
   }

   cout<<maxi<<endl;


    }
   
    return 0;
}