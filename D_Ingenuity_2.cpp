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
        int n;cin>>n;
        string s;cin>>s;
        vi v(4,0);
        REP(i,0,n-1){
            if(s[i]=='N')v[0]++;
            if(s[i]=='S')v[1]++;
            if(s[i]=='E')v[2]++;
            if(s[i]=='W')v[3]++;
        }
        if((v[0]+v[1])%2==0 && (v[2]+v[3])%2==0 && (n>2 || v[0]>1 || v[1]>1 || v[2]>1 || v[3]>1)){
            vi tmp(4,0);
            string ans(n,'R');
            REP(i,0,n-1){
                if(s[i]=='N' && tmp[0]==0){
                    ans[i]='R';tmp[0]=1;
                }
                else if(s[i]=='N' && tmp[0]==1){ans[i]='H' ;tmp[0]=0;}

                if(s[i]=='S' && tmp[1]==0){
                    ans[i]='R';tmp[1]=1;
                }
                else if(s[i]=='S' && tmp[1]==1){ans[i]='H' ;tmp[1]=0;}

                if(s[i]=='E' && tmp[2]==0){
                    ans[i]='H';tmp[2]=1;
                }
                else if(s[i]=='E' && tmp[2]==1){ans[i]='R' ;tmp[2]=0;}

                if(s[i]=='W' && tmp[3]==0){
                    ans[i]='H';tmp[3]=1;
                }
                else if(s[i]=='W' && tmp[3]==1){ans[i]='R' ;tmp[3]=0;}
            }
            // if(v[0]>=1 && v[1]>=1){
            //     REP(i,0,n-1){
            //         if(s[i]=='S'){
            //             ans[i]='R';break;
            //         }
            //     }
            // }
            // if(v[2]>=1 && v[3]>=1){
            //     REP(i,0,n-1){
            //         if(s[i]=='W'){
            //             ans[i]='H';break;
            //         }
            //     }
            // }
            cout<<ans<<endl;
            // if(n==4 && v[0]==1 && v[1]==1 && v[2]==1 && v[3]==1){
            //     REP(i,0,3){
            //         if(s[i]=='N'){ans[i]='R';}
            //         if(s[i]=='S'){ans[i]='H';}
            //     }
            // }
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}