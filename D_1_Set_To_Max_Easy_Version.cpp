#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<long long> vi;
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
        ll n;cin>>n;
        vi v1,v2;
        REP(i,0,n-1){
            ll a;cin>>a;
            v1.push_back(a);
        }
        REP(i,0,n-1){
            ll a;cin>>a;
            v2.push_back(a);
        }
        ll flag=1;
        REP(i,0,n-1){
            ll flag1=0;
            ll l=i-1,r=i+1,target=v2[i];
            if(v1[i]<v2[i]){
                while(l>=0){
                    if(v1[l]==target && v2[l]>=target){flag1=1;break;}
                    if(v1[l]>target)break;
                    if(v2[l]<target)break;
                    l--;
                }
                while(r<n){
                    if(v1[r]==target && v2[r]>=target){flag1=1;break;}
                    if(v1[r]>target)break;
                    if(v2[r]<target)break;
                    r++;
                }

            }
            else if(v1[i]==v2[i]){flag1=1;}
            if(flag1==0){flag=0;break;}
        }
        if(flag==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
}