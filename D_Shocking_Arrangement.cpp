#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
        vi v;
        stack<ll> s1,s2,s3;
        REP(i,0,n-1){
            ll a;cin>>a;
            v.push_back(a);
            if(a==0)s3.push(0);
            else if(a<0)s2.push(a);
            else s1.push(a);
        }
        vi ans;
        ll tmp=0;
     if(s3.size()!=n){
        while(!s3.empty()){
            ans.push_back(0);
            s3.pop();
        }
        tmp+=s1.top();
        ans.push_back(s1.top());
        s1.pop();
        while(!s1.empty() || !s2.empty()){
         if(tmp>0){
            while(tmp>0){
                tmp+=s2.top();
                ans.push_back(s2.top());
                s2.pop();
            }
         }
         else{
            while(s1.size()!=0 && tmp<=0){
                tmp+=s1.top();
                ans.push_back(s1.top());
                s1.pop();
            }
         }
        }
        // cout<<s1.size()<<endl;
        cout<<"Yes"<<endl;
        for(auto it:ans)cout<<it<<" ";
        cout<<endl;
     }
     else{
        cout<<"No"<<endl;
     }

        
    }
}