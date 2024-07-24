#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
        int n;cin>>n;
        vi v;
        ll avg=0,sum=0;
        REP(i,0,n-1){
            int a;cin>>a;sum+=a;
            v.push_back(a);
        }
        ll flag=1;
        if(sum%n!=0)flag=0;
        avg=sum/n;
        msi m1,m2;
       
            
            REP(k,0,n-1){
                ll z=v[k]-avg,cnt=0;
                if(z==0)cnt=1;
                REP(i,0,30){
                    REP(j,i+1,30){
                        if((1LL<<j)-(1LL<<i)==abs(z)){
                            if(z>0){m1[(1LL<<j)]++;m2[(1LL<<i)]++;}
                            if(z<0){m1[(1LL<<i)]++;m2[(1LL<<j)]++;}
                            cnt=1;
                            break;
                        }
                       
                        
                    }
                     if(cnt>0)break;
                    
                }
                if(cnt==0)flag=0;
                
            }
            // cout<<m1.size()<<endl;
            
            // for(auto it:m2)cout<<it.first<<" "<<it.second<<endl;
            for(auto it:m1){
                if(m2[it.first]!=it.second)flag=0;
            }
            if(flag==0)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        
    }
}