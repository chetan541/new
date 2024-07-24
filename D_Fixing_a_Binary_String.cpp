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
bool check(string &s,int k,int ind,int n){
    string tmp;
    if(ind!=n)tmp.append(s.begin()+ind,s.end());
    for(int i=ind-1;i>=0;i--){
        tmp.pb(s[i]);
    }
    // cout<<tmp<<endl;
    char prev=-'1';
    REP(i,0,n-1){
        if(tmp[i]==prev)return false;
        else prev=tmp[i];
        REP(j,i,i+k-1){
            if(tmp[j]!=tmp[i])return false;
        }
        i+=k-1;
    }
    
    return true;
    
    
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        // cout<<check(s,k,3,n);
        int tmp=1,tmp1;
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[i+1])tmp++;
            else break;
        }
        tmp1=tmp;
        tmp=min(k,tmp);
        char prev='-1';
        bool flag=false;
        flag=check(s,k,n,n);
        int ans=n;
        
        REP(i,0,n-1){
            // cout<<i+k-tmp<<endl;
            ll x=0;
            REP(j,i,i+k-1){
                if(s[i]==s[j])x++;
                else break;
            }
            // cout<<x<<endl;
            if(x<k){
                if(!flag){
                    flag=check(s,k,i+x,n);
                    if(flag)ans=i+x;
                    // cout<<i+k-tmp<<endl;
                    }

                if(!flag){
                    
                    flag=check(s,k,i+(k-tmp),n);
                    if(flag)ans=i+k-tmp;
                }
                break;

            }
            else if(x==k){
                if(i+k<=n-1 && s[i]==s[i+k]){
                    if(!flag){
                    
                    flag=check(s,k,i+(k-tmp),n);
                    if(flag)ans=i+k-tmp;
                }
                    if(!flag){flag=check(s,k,i+k,n);
                    if(flag)ans=i+k;}
                    break;
                    }
            }
            i+=k-1;
        }
        if(flag)cout<<ans<<endl;
        else cout<<-1<<endl;
        


        
    }
}