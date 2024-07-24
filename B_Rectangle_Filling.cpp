#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first 
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
  
  
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
        int n,m;cin>>n>>m;
        char arr[n][m];
        // vi v;
        REP(i,0,n-1){
           REP(j,0,m-1){
            cin>>arr[i][j];
            // cout<<arr[i][j]<<" ";
           }
        }
        int flag=0,cnt1=0,cnt2=0;
        REP(i,0,m-1){
           if(arr[0][i]=='W')cnt1=1;
           if(arr[0][i]=='B')cnt2=1;
        }
        REP(i,0,m-1){
           if(arr[n-1][i]=='W' && cnt1==1)cnt1=2;
           if(arr[n-1][i]=='B' && cnt2==1)cnt2=2;
        }
        REP(i,0,n-1){
           if(arr[i][0]=='W' && cnt1==2)cnt1=3;
           if(arr[i][0]=='B' && cnt2==2)cnt2=3;
        }
        REP(i,0,n-1){
           if(arr[i][m-1]=='W' && cnt1==3)cnt1=4;
           if(arr[i][m-1]=='B' && cnt2==3)cnt2=4;
        }
        if(cnt1==4 || cnt2==4)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}