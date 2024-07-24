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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k,d;cin>>n>>k>>d;
        vi v1,v2;
        REP(i,0,n-1){
            int a;cin>>a;
            v1.push_back(a);
        }
        REP(j,0,k-1){
            int b;cin>>b;
            v2.push_back(b);
        }
        int ext;
        ll ans=INT_MIN;
        if(v1[0]==1){
           ans= 1LL*(d+1)/2;
        }
        else if(v1[0]==0)ans=1LL*(d)/2;
        else ans= 1LL*(d+1)/2-1;
        int steps=min(2*n,d);
        
        REP(i,0,steps-1){
            int temp=0;
            REP(j,0,n-1){
                if(i%k!=0){
                if(v2[i%k-1]>=j+1){
                    if(i>0)v1[j]++;
                    
                }
                }
                else{
                    if(i>0){
                        if(v2[k-1]>=j+1){
                    if(i>0)v1[j]++;
                    
                }
                    }
                }
                if(v1[j]==j+1)temp++;
                // cout<<j<<" "<<v2[i%k-1]<<" "<<temp<<endl;
            }
            
            ans=max(1LL*ans,1LL*temp+1LL*(d-i-1)/2);
            // cout<<temp<<" "<<ans<<endl;
        }  
        // if(ans==12500){
        //     for(auto it:v2)cout<<it<<" ";
        // }
        cout<<ans<<endl;
    }
}