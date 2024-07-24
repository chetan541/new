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
    int t;cin>>t;
    while(t--){
        ll modulo=998244353;
        ll l,r;cin>>l>>r;
        ll tmp=l,cnt=0;
        while(tmp<=r){
            cnt++;tmp*=2;
        }
        ll lim1=r/pow(2,cnt-1);
        if(cnt==0)lim1=l;
        ll sum=0;
        ll lim2;
        if(cnt>=2){
            lim2=r/(3*pow(2,cnt-2));
        }
        else lim2=0;
        if(lim2>=l){
            sum=(sum+((lim2-l+1)*cnt)%modulo)%modulo;
            sum=(sum+((lim1-lim2)*1)%modulo)%modulo;
        }
        else{
            sum+=(lim1-l+1)%modulo;
        }

        // REP(i,l,lim){
        //     if(i*3*pow(2,cnt-2)<=r && cnt>=2){
        //         sum=(sum+cnt)%modulo;
        //     }
        //     else sum+=1;
        // }  
        cout<<cnt<<" "<<sum<<endl; 
    }
}