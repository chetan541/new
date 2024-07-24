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
 
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll ans=0;
        REP(i,0,n-1){
            cout<<"?"<<" "<<ans<<" "<<ans<<" "<<i<<" "<<i<<endl;
            cout.flush();
            char tmp;cin>>tmp;
            // cout<<tmp<<endl;
            if(tmp=='<')ans=i;
        }
        // vi vec;
        int x=0;
        REP(i,0,n-1){
         cout<<"?"<<" "<<ans<<" "<<x<<" "<<ans<<" "<<i<<endl;
         cout.flush();
         char tmp;cin>>tmp;
        //  cout<<tmp<<endl;
         if(tmp=='<')x=i;
         else if(tmp=='='){
            cout<<"?"<<" "<<x<<" "<<x<<" "<<i<<" "<<i<<endl;
            cout.flush();
            char acc;
            // cout<<"hi"<<endl;
            cin>>acc;
            // cout<<tmp<<endl;
            if(acc=='>')x=i;
         }
        }
        // if(ans==x && x==0)x++;
        // else x=0;
        cout<<"!"<<" "<<ans<<" "<<x<<endl;
        cout.flush();
        
    }
}