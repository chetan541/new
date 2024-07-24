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
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));

 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_back(p);
    //}
   // return v;
//}

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    
        int n,k;cin>>n>>k;
       string s;cin>>s;
       vector<string> ans;
       string temp;
       REP(i,0,n-1){
         temp+=s[i];
         ans.push_back(temp);
       }
       vector<string> out;
       REP(i,0,n-1){
         int x=k/ans[i].size(),y=k%ans[i].size();
         string z;
         REP(j,1,x){
            z+=ans[i];
         }
         REP(j,0,y-1){
            z+=ans[i][j];
         }
         out.push_back(z);
       }
       sort(out.begin(),out.end());
       
      //  if(ans.size()==n-1 && s[n-1]<s[0])ans.push_back(s[n-1]);
       
      //  int x=k/ans.size();
      //  int tmp=k%ans.size();
      //  string out;
      //  REP(i,1,x){
      //   out+=ans;
      //  }
      //  REP(i,0,tmp-1){
      //   out+=ans[i];
      //  }
      // cout<<out[0][5]<<endl;
       cout<<out[0];
        
    }
