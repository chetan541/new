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
        ll n,m;cin>>n>>m;
        
        vi v1,v2;
        for(int i=62;i>=0;i--){
            // cout<<(n&(1LL<<i))<<" "<<(m&(1LL<<i))<<endl;
            if((n&(1LL<<i))!=0 && (m&(1LL<<i))==0)v1.push_back(i);
            else if((m&(1LL<<i))!=0 && (n&(1LL<<i))==0)v2.push_back(i);
        }
        vi ans;
        ll flag=1;
        ll tmp=n;
        ll x=0;
       for(auto it :v2){
        x+=(1LL<<it);
       }
       if(v1.size()!=0 && x<(1LL<<v1[0]) && x+(1LL<<v1[0])<tmp){
        if(x+(1LL<<v1[0])<tmp && x!=0){
            tmp^=(x+(1LL<<v1[0]));
        }
       }
       else {flag=0;}
        // for(auto it:v2){
        //     auto vt=upper_bound(v1.begin(),v1.end(),it);
        //     if(vt==v1.end()){flag=0;break;}
        //     if(((1LL<<(*vt))+(1LL<<it))>=tmp){flag=0;break;}
        //     else {tmp=tmp^((1LL<<(*vt))+(1LL<<it));
        //     // v1.erase(vt);
        //     // cout<<tmp<<endl;
        //     ans.push_back(tmp);}

        // }
        
        
        
        // for(auto it:v1)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:v2)cout<<it<<" ";
        // cout<<endl;
        // cout<<(481885160128643072^45035996273704960)<<endl;
        if(flag==0)cout<<-1<<endl;
        else{
            if(tmp==m || tmp==n){
                cout<<1<<endl;
                cout<<n<<" ";
                cout<<m<<" ";
            }
            else{
                cout<<2<<endl;
                cout<<n<<" ";
                cout<<tmp<<" ";
                cout<<m<<" ";
            }
            cout<<endl;
        }
        
    }
}