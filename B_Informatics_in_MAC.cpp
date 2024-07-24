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
int findMex(const std::vector<int>& arr) {
    std::unordered_set<int> uniqueElements(arr.begin(), arr.end());

    int mex = 0;
    while (uniqueElements.count(mex) > 0) {
        ++mex;
    }

    return mex;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        ll cnt=0;
        // REP(i,0,n-1){
        //     if(v[i]==cnt)cnt++;
        // }
        cnt=findMex(v);
        int ind=-1,ind2=-1;
        ll tmp=cnt-1;
        msi m1,m2;
        ll flag=1;
        REP(i,0,n-1){
            // cout<<tmp<<" "<<v[i]<<" "<<m1[v[i]]<<endl;
            
            if(v[i]<cnt){
                if(m1[v[i]]==0){tmp--;m1[v[i]]++;}
            }
            if(tmp==-1){ind=i;break;}

        }
        if(ind<n && ind!=-1){
            tmp=cnt-1;
            REP(i,ind+1,n-1){
            
            if(v[i]<cnt){
                if(m2[v[i]]==0){tmp--;m2[v[i]]++;}
            }
            if(tmp==-1){ind2=i;break;}

        }
        }
        if(ind<n && ind!=-1 && ind2<n && ind2!=-1){
            cout<<2<<endl;
            cout<<1<<" "<<ind+1<<endl;
            cout<<ind+2<<" "<<n<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
    }
}